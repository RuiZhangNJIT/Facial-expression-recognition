#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cmath>
#include <iostream>

using namespace cv;
using namespace std;

const double PI = 3.14159265;

// ref: http://blog.csdn.net/watkinsong/article/details/7876361
Mat getMyGabor(int width, int height, int U, int V, double Kmax, double f,
	double sigma, int ktype, const string& kernel_name)
{
	//CV_ASSERT(width % 2 == 0 && height % 2 == 0);
	//CV_ASSERT(ktype == CV_32F || ktype == CV_64F);

	int half_width = width / 2;
	int half_height = height / 2;
	double Qu = PI*U / 8;
	double sqsigma = sigma*sigma;
	double Kv = Kmax / pow(f, V);
	double postmean = exp(-sqsigma / 2);

	Mat kernel_re(width, height, ktype);
	Mat kernel_im(width, height, ktype);
	Mat kernel_mag(width, height, ktype);

	double tmp1, tmp2, tmp3;
	for (int j = -half_height; j <= half_height; j++) {
		for (int i = -half_width; i <= half_width; i++) {
			tmp1 = exp(-(Kv*Kv*(j*j + i*i)) / (2 * sqsigma));
			tmp2 = cos(Kv*cos(Qu)*i + Kv*sin(Qu)*j) - postmean;
			tmp3 = sin(Kv*cos(Qu)*i + Kv*sin(Qu)*j);

			if (ktype == CV_32F)
				kernel_re.at<float>(j + half_height, i + half_width) =
				(float)(Kv*Kv*tmp1*tmp2 / sqsigma);
			else
				kernel_re.at<double>(j + half_height, i + half_width) =
				(double)(Kv*Kv*tmp1*tmp2 / sqsigma);

			if (ktype == CV_32F)
				kernel_im.at<float>(j + half_height, i + half_width) =
				(float)(Kv*Kv*tmp1*tmp3 / sqsigma);
			else
				kernel_im.at<double>(j + half_height, i + half_width) =
				(double)(Kv*Kv*tmp1*tmp3 / sqsigma);
		}
	}

	magnitude(kernel_re, kernel_im, kernel_mag);

	if (kernel_name.compare("real") == 0)
		return kernel_re;
	else if (kernel_name.compare("imag") == 0)
		return kernel_im;
	else if (kernel_name.compare("mag") == 0)
		return kernel_mag;
	else
		printf("Invalid kernel name!\n");
}

void construct_gabor_bank()
{
	double Kmax = PI / 2;
	double f = sqrt(2.0);
	double sigma = 2 * PI;
	int U = 7;
	int V = 4;
	int GaborH = 129;
	int GaborW = 129;

	Mat kernel;
	Mat totalMat;
	for (U = 0; U < 8; U++) {
		Mat colMat;
		for (V = 0; V < 5; V++) {
			kernel = getMyGabor(GaborW, GaborH, U, V,
				Kmax, f, sigma, CV_64F, "real");

			//show gabor kernel
			normalize(kernel, kernel, 0, 1, CV_MINMAX);
			printf("U%dV%d\n", U, V);
			//imshow("gabor", kernel);
			//waitKey(0);

			if (V == 0)
				colMat = kernel;
			else
				vconcat(colMat, kernel, colMat);
		}
		if (U == 0)
			totalMat = colMat;
		else
			hconcat(totalMat, colMat, totalMat);
	}

	imshow("gabor bank", totalMat);
	//imwrite("gabor_bank.jpg",totalMat);
	waitKey(0);
}

Mat gabor_filter(Mat& img)
{
	// variables for gabor filter
	double Kmax = PI / 2;
	double f = sqrt(2.0);
	double sigma = 2 * PI;
	int U = 7;
	int V = 4;
	int GaborH = 129;
	int GaborW = 129;

	// 
	Mat kernel_re, kernel_im;
	Mat dst_re, dst_im, dst_mag;

	// variables for filter2D
	Point archor(-1, -1);
	int ddepth = -1;
	double delta = 0;

	// filter image with gabor bank
	Mat totalMat;
	for (U = 0; U < 8; U++) {
		Mat colMat;
		for (V = 0; V < 5; V++) {
			kernel_re = getMyGabor(GaborW, GaborH, U, V,
				Kmax, f, sigma, CV_64F, "real");
			kernel_im = getMyGabor(GaborW, GaborH, U, V,
				Kmax, f, sigma, CV_64F, "imag");

			filter2D(img, dst_re, ddepth, kernel_re);
			filter2D(img, dst_im, ddepth, kernel_im);

			dst_mag.create(img.rows, img.cols, CV_32FC1);
			magnitude(Mat_<float>(dst_re), Mat_<float>(dst_im),
				dst_mag);

			//show gabor kernel
			normalize(dst_mag, dst_mag, 0, 1, CV_MINMAX);
			printf("U%dV%d\n", U, V);
			//imshow("dst_mag", dst_mag);
			//waitKey(0);

			if (V == 0)
				colMat = dst_mag;
			else
				vconcat(colMat, dst_mag, colMat);
		}
		if (U == 0)
			totalMat = colMat;
		else
			hconcat(totalMat, colMat, totalMat);
	}

	return totalMat;
}