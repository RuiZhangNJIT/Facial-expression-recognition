// Neutral.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FacialExpression.h"
#include "Neutral.h"
#include "afxdialogex.h"

#include "Collected.h"

#include<opencv2\opencv.hpp>
#include <stdlib.h>
using namespace cv;
using namespace std;


// Neutral dialog

IMPLEMENT_DYNAMIC(Neutral, CDialogEx)

Neutral::Neutral(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_neutral, pParent)
{

}

Neutral::~Neutral()
{
}

void Neutral::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Neutral, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Neutral::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_BUTTON2, &Neutral::OnBnClickedClear)
	ON_BN_CLICKED(IDC_BUTTON3, &Neutral::OnBnClickedRecording)
END_MESSAGE_MAP()


// Neutral message handlers

Mat frame2;
int tag2 = 0;
int record2 = 0;
int click2 = 0;
//mouse click the face area

Point l_start2;
Point l_end2;
Point mouse2 = (0, 0);
Point mouse_last2 = (0, 0);
int width2;
int height2;
int i2 = 0;
int j7 = 0;

Point mouse_test02 = (0, 0);
Point mouse_test12 = (0, 0);

//face area(ROI) function
void Face_ROI2(Point Begin, Point Finished)
{

	// caculate width & height
	width2 = Begin.x - Finished.x;
	height2 = Begin.y - Finished.y;
	//rectangle(src, start, center, Scalar(255, 0, 0));
}

void Face_ROI_test2(Point Begin)
{
	width2 = 200;
	height2 = 220;
	mouse_test02.x = Begin.x;
	mouse_test02.y = Begin.y - 100;
	mouse_test12.x = mouse_test02.x + width2;
	mouse_test12.y = mouse_test02.y + height2;

}

//mouse click function

void OnMouseAction2(int event, int x, int y, int flags, void *ustc)
{


	if (event == CV_EVENT_LBUTTONDOWN)
	{
		//cout << "hehe" << endl;
		mouse2.x = x;
		mouse2.y = y;
		click2++;
	}


}




void Neutral::OnBnClickedOpen()
{
	// TODO: Add your control notification handler code here
	//cvNamedWindow("Readvideo", 1);
	VideoCapture capture2(0);
	while (1)
	{
		capture2 >> frame2;

		if (record2 == 1)
		{
			j7++;
		}

		//click mouse
		setMouseCallback("ReadVideo", OnMouseAction2);

		circle(frame2, mouse2, 5, Scalar(0, 0, 255), 2);
		//circle(frame, mouse_last, 5, Scalar(0, 0, 255), 2);
		Face_ROI_test2(mouse2);
		circle(frame2, mouse_test02, 5, Scalar(0, 0, 255), 2);
		circle(frame2, mouse_test12, 5, Scalar(0, 0, 255), 2);
		rectangle(frame2, mouse_test02, mouse_test12, Scalar(255, 0, 0));


		//show the images

		imshow("ReadVideo", frame2);

		//make sure the click point won`t disappear

		if (click2 < 2)
		{
			mouse_last2 = mouse2;
		}

		// if (record == 1 && j%200==0)
		//{
		// OnBnClickedRecording();
		//}

		//AllocConsole();
		//freopen("CONOUT$", "w+t", stdout);
		if (j7 % 3 == 0 && record2 == 1)
		{
			//cout <<j<< "=j is equal 0" << endl;
			OnBnClickedRecording();
		}
		if (i2 == 200)
		{
			capture2.release();
			break;

		}


		waitKey(30);


	}
}


void Neutral::OnBnClickedClear()
{
	// TODO: Add your control notification handler code here
	mouse2.x = 0;
	mouse_last2.x = 0;
	mouse2.y = 0;
	mouse_last2.y = 0;

	click2 = 0;
}


void Neutral::OnBnClickedRecording()
{
	// TODO: Add your control notification handler code here
	record2 = 1;
	//AllocConsole();
	//freopen("CONOUT$", "w+t", stdout);
	//cout << j % 200 << endl;

	//while (record==1 && j%200==0)
	//{
	//Face_ROI(mouse,mouse_last);


	//write frame to Angry File
	//while (record)
	//{
	Face_ROI2(mouse2, mouse_last2);


	//write frame to Angry File
	char c[20];
	String buf1, buf2, buf3;
	buf1 = "Neutral//";
	buf2 = _itoa(i2, c, 10);
	buf3 = ".bmp";
	buf1 = buf1 + buf2 + buf3;

	//open console to test result of buf1
	//	AllocConsole();
	//	freopen("CONOUT$", "w+t", stdout);


	Rect rect(mouse_test02.x, mouse_test02.y, 200, 220);
	Mat image = frame2(rect);
	Mat image_dst;
	cvtColor(image, image_dst, CV_BGR2GRAY);

	imwrite(buf1, image_dst);
	i2++;
	if (i2 == 200)
	{
		Collected dialog_test;

		dialog_test.DoModal();

		//break;
	}

	//}




}
