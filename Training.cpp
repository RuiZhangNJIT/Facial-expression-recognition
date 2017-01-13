// Training.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FacialExpression.h"
#include "Training.h"
#include "afxdialogex.h"

#include "cvgabor.h"

// Training dialog

IMPLEMENT_DYNAMIC(Training, CDialogEx)

Training::Training(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Traning, pParent)
{

}

Training::~Training()
{
}

void Training::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Training, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Training::OnBnClickedAngry)
	ON_BN_CLICKED(IDC_BUTTON2, &Training::OnBnClickedHappy)
	ON_BN_CLICKED(IDC_BUTTON3, &Training::OnBnClickedNeutral)
	ON_BN_CLICKED(IDC_BUTTON4, &Training::OnBnClickedSuprise)
END_MESSAGE_MAP()


// Training message handlers


void Training::OnBnClickedAngry()
{
	// TODO: Add your control notification handler code here

	//initial the gabor_filter`s parameters

	double Sigma = PI;
	double F = sqrt(3.0);
	CvGabor gabor(PI, 2, Sigma, F);

	
	for (int i = 0; i < 200; i++)
	{
		//image read from Angry File
		char c[20];
		String buf1, buf2, buf3;
		buf1 = "Angry//";
		buf2 = _itoa(i, c, 10);
		buf3 = ".bmp";
		buf1 = buf1 + buf2 + buf3;



		

		Mat img = imread(buf1);
		Mat new_img;

		//resize the img
		
		resize(img, new_img, Size(200, 200));



		Mat reimg;

		//gabor_filter
		gabor.conv_img(new_img, reimg, 3);

		imshow("realimg",reimg);


		//save gabor_filtered img in Gabor_img File
		char c1[20];
		String buf11, buf21, buf31;
		buf11 = "Gabor_Angry//";
		buf21 = _itoa(i, c1, 10);
		buf31 = ".bmp";
		buf11 = buf11 + buf21 + buf31;

		imwrite(buf11, reimg);
	}

}


void Training::OnBnClickedHappy()
{
	// TODO: Add your control notification handler code here
	double Sigma = PI;
	double F = sqrt(3.0);
	CvGabor gabor(PI, 2, Sigma, F);


	for (int i = 0; i < 200; i++)
	{
		//image read from Happy File
		char c[20];
		String buf1, buf2, buf3;
		buf1 = "Happy//";
		buf2 = _itoa(i, c, 10);
		buf3 = ".bmp";
		buf1 = buf1 + buf2 + buf3;





		Mat img = imread(buf1);
		Mat new_img;

		//resize the img

		resize(img, new_img, Size(200, 200));



		Mat reimg;

		//gabor_filter
		gabor.conv_img(new_img, reimg, 3);

		imshow("realimg", reimg);


		//save gabor_filtered img in Gabor_img File
		char c1[20];
		String buf11, buf21, buf31;
		buf11 = "Gabor_Happy//";
		buf21 = _itoa(i, c1, 10);
		buf31 = ".bmp";
		buf11 = buf11 + buf21 + buf31;

		imwrite(buf11, reimg);
	}
}


void Training::OnBnClickedNeutral()
{
	// TODO: Add your control notification handler code here
	double Sigma = PI;
	double F = sqrt(3.0);
	CvGabor gabor(PI, 2, Sigma, F);


	for (int i = 0; i < 200; i++)
	{
		//image read from Happy File
		char c[20];
		String buf1, buf2, buf3;
		buf1 = "Neutral//";
		buf2 = _itoa(i, c, 10);
		buf3 = ".bmp";
		buf1 = buf1 + buf2 + buf3;

		AllocConsole();
		freopen("CONOUT$", "w+t", stdout);

		cout << buf1;

		Mat img = imread(buf1);
		Mat new_img;
		//imshow("oringinal", img);

		//resize the img

		resize(img, new_img, Size(200, 200));



		Mat reimg;

		//gabor_filter
		gabor.conv_img(new_img, reimg, 3);

		imshow("realimg", reimg);


		//save gabor_filtered img in Gabor_img File
		char c1[20];
		String buf11, buf21, buf31;
		buf11 = "Gabor_Neutral//";
		buf21 = _itoa(i, c1, 10);
		buf31 = ".bmp";
		buf11 = buf11 + buf21 + buf31;

		imwrite(buf11, reimg);
	}
}


void Training::OnBnClickedSuprise()
{
	// TODO: Add your control notification handler code here
	double Sigma = PI;
	double F = sqrt(3.0);
	CvGabor gabor(PI, 2, Sigma, F);


	for (int i = 0; i < 200; i++)
	{
		//image read from Angry File
		char c[20];
		String buf1, buf2, buf3;
		buf1 = "Surprise//";
		buf2 = _itoa(i, c, 10);
		buf3 = ".bmp";
		buf1 = buf1 + buf2 + buf3;





		Mat img = imread(buf1);
		Mat new_img;

		//resize the img

		resize(img, new_img, Size(200, 200));



		Mat reimg;

		//gabor_filter
		gabor.conv_img(new_img, reimg, 3);

		imshow("realimg", reimg);


		//save gabor_filtered img in Gabor_img File
		char c1[20];
		String buf11, buf21, buf31;
		buf11 = "Gabor_Surprise//";
		buf21 = _itoa(i, c1, 10);
		buf31 = ".bmp";
		buf11 = buf11 + buf21 + buf31;

		imwrite(buf11, reimg);
	}

}
