// Testing.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FacialExpression.h"
#include "Testing.h"
#include "afxdialogex.h"
#include "Collected.h"
#include "cvgabor.h"

#include<opencv2\opencv.hpp>

using namespace cv;
using namespace std;

// Testing dialog

IMPLEMENT_DYNAMIC(Testing, CDialogEx)

Testing::Testing(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Testing::~Testing()
{
}

void Testing::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Testing, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Testing::OnBnClickedOpenCamera)
	ON_BN_CLICKED(IDC_BUTTON2, &Testing::OnBnClickedMouseClear)
	ON_BN_CLICKED(IDC_BUTTON3, &Testing::OnBnClickedTesting)
END_MESSAGE_MAP()


// Testing message handlers

Mat frame5;
int tag5 = 0;
int record5 = 0;
int click5 = 0;
//mouse click the face area

Point l_start5;
Point l_end5;
Point mouse5 = (0, 0);
Point mouse_last5 = (0, 0);
int width5;
int height5;
int i5 = 0;
int j5 = 0;

Point mouse_test5 = (0, 0);
Point mouse_test15 = (0, 0);

//face area(ROI) function
void Face_ROI5(Point Begin, Point Finished)
{

	// caculate width & height
	width5 = Begin.x - Finished.x;
	height5 = Begin.y - Finished.y;
	//rectangle(src, start, center, Scalar(255, 0, 0));
}

void Face_ROI_test5(Point Begin)
{
	width5 = 200;
	height5 = 220;
	mouse_test5.x = Begin.x;
	mouse_test5.y = Begin.y - 100;
	mouse_test15.x = mouse_test5.x + width5;
	mouse_test15.y = mouse_test5.y + height5;

}
//mouse click function

void OnMouseAction5(int event, int x, int y, int flags, void *ustc)
{


	if (event == CV_EVENT_LBUTTONDOWN)
	{
		//cout << "hehe" << endl;
		mouse5.x = x;
		mouse5.y = y;
		click5++;
	}


}



void Testing::OnBnClickedOpenCamera()
{
	// TODO: Add your control notification handler code here
	
	VideoCapture capture5(0);
	while (1)
	{
		capture5 >> frame5;

		if (record5 == 1)
		{
			j5++;
		}

		//click mouse
		setMouseCallback("ReadVideo", OnMouseAction5);

		circle(frame5, mouse5, 5, Scalar(0, 0, 255), 2);
		//circle(frame, mouse_last, 5, Scalar(0, 0, 255), 2);
		Face_ROI_test5(mouse5);
		circle(frame5, mouse_test5, 5, Scalar(0, 0, 255), 2);
		circle(frame5, mouse_test15, 5, Scalar(0, 0, 255), 2);
		rectangle(frame5, mouse_test5, mouse_test15, Scalar(255, 0, 0));


		//show the images

		imshow("ReadVideo", frame5);

		//make sure the click point won`t disappear

		if (click5 < 2)
		{
			mouse_last5 = mouse5;
		}

		// if (record == 1 && j%200==0)
		//{
		// OnBnClickedRecording();
		//}

		//AllocConsole();
		//freopen("CONOUT$", "w+t", stdout);
		if (j5 % 3 == 0 && record5 == 1)
		{
			//cout <<j<< "=j is equal 0" << endl;
			OnBnClickedTesting();
		}
		if (i5 == 100)
		{
			capture5.release();
			break;

		}


		waitKey(30);


	}
}


void Testing::OnBnClickedMouseClear()
{
	// TODO: Add your control notification handler code here
	mouse5.x = 0;
	mouse_last5.x = 0;
	mouse5.y = 0;
	mouse_last5.y = 0;

	click5 = 0;
	
}


void Testing::OnBnClickedTesting()
{
	// TODO: Add your control notification handler code here
	record5 = 1;

	


		//write frame to Angry File
		char c[20];
		String buf1, buf2, buf3;
		buf1 = "test//";
		buf2 = _itoa(i5, c, 10);
		buf3 = ".bmp";
		buf1 = buf1 + buf2 + buf3;

		//open console to test result of buf1
		//	AllocConsole();
		//	freopen("CONOUT$", "w+t", stdout);


		Rect rect(mouse_test5.x, mouse_test5.y, 200, 220);
		Mat image = frame5(rect);
		Mat image_dst;
		//Pre_adjust(resize image,change image to black image)
		cvtColor(image, image_dst, CV_BGR2GRAY);



		//image write
		imwrite(buf1, image_dst);
		i5++;
		if (i5 == 100)
		{
			Collected dialog_test;

			dialog_test.DoModal();

			
		}

	

	double Sigma = PI;
	double F = sqrt(3.0);
	CvGabor gabor(PI, 2, Sigma, F);


	
		//image read from Happy File
		
		//resize the img
	Mat new_img;

		resize(image, new_img, Size(200, 200));



		Mat reimg;

		//gabor_filter
		gabor.conv_img(new_img, reimg, 3);

		//imshow("realimg", reimg);


		//save gabor_filtered img in Gabor_img File
		char c1[20];
		String buf11, buf21, buf31;
		buf11 = "Gabor_test//";
		buf21 = _itoa(i5, c1, 10);
		buf31 = ".bmp";
		buf11 = buf11 + buf21 + buf31;

		imwrite(buf11, reimg);
	
}
