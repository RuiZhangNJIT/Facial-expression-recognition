// Surprise.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FacialExpression.h"
#include "Surprise.h"
#include "afxdialogex.h"
#include "Collected.h"

#include<opencv2\opencv.hpp>
#include <stdlib.h>
using namespace cv;
using namespace std;

// Surprise dialog


IMPLEMENT_DYNAMIC(Surprise, CDialogEx)

Surprise::Surprise(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Surpurise, pParent)
{

}

Surprise::~Surprise()
{
}

void Surprise::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Surprise, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Surprise::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_BUTTON2, &Surprise::OnBnClickedMouseClear)
	ON_BN_CLICKED(IDC_BUTTON3, &Surprise::OnBnClickedRecording)
END_MESSAGE_MAP()


// Surprise message handlers

Mat frame3;
int tag3 = 0;
int record3 = 0;
int click3 = 0;
//mouse click the face area

Point l_start3;
Point l_end3;
Point mouse3 = (0, 0);
Point mouse_last3 = (0, 0);
int width3;
int height3;
int i3 = 0;
int j8 = 0;

Point mouse_test03 = (0, 0);
Point mouse_test13 = (0, 0);


//face area(ROI) function
void Face_ROI3(Point Begin, Point Finished)
{

	// caculate width & height
	width3 = Begin.x - Finished.x;
	height3 = Begin.y - Finished.y;
	//rectangle(src, start, center, Scalar(255, 0, 0));
}

void Face_ROI_test3(Point Begin)
{
	width3 = 200;
	height3 = 220;
	mouse_test03.x = Begin.x;
	mouse_test03.y = Begin.y - 100;
	mouse_test13.x = mouse_test03.x + width3;
	mouse_test13.y = mouse_test03.y + height3;

}

//mouse click function

void OnMouseAction3(int event, int x, int y, int flags, void *ustc)
{


	if (event == CV_EVENT_LBUTTONDOWN)
	{
		//cout << "hehe" << endl;
		mouse3.x = x;
		mouse3.y = y;
		click3++;
	}


}


void Surprise::OnBnClickedOpen()
{
	// TODO: Add your control notification handler code here
	VideoCapture capture3(0);
	while (1)
	{
		capture3 >> frame3;

		if (record3 == 1)
		{
			j8++;
		}

		//click mouse
		setMouseCallback("ReadVideo", OnMouseAction3);

		circle(frame3, mouse3, 5, Scalar(0, 0, 255), 2);
		//circle(frame, mouse_last, 5, Scalar(0, 0, 255), 2);
		Face_ROI_test3(mouse3);
		circle(frame3, mouse_test03, 5, Scalar(0, 0, 255), 2);
		circle(frame3, mouse_test13, 5, Scalar(0, 0, 255), 2);
		rectangle(frame3, mouse_test03, mouse_test13, Scalar(255, 0, 0));


		//show the images

		imshow("ReadVideo", frame3);

		//make sure the click point won`t disappear

		if (click3 < 2)
		{
			mouse_last3 = mouse3;
		}

		// if (record == 1 && j%200==0)
		//{
		// OnBnClickedRecording();
		//}

		//AllocConsole();
		//freopen("CONOUT$", "w+t", stdout);
		if (j8 % 3 == 0 && record3 == 1)
		{
			//cout <<j<< "=j is equal 0" << endl;
			OnBnClickedRecording();
		}
		if (i3 == 200)
		{
			capture3.release();
			break;

		}


		waitKey(30);


	}

}


void Surprise::OnBnClickedMouseClear()
{
	// TODO: Add your control notification handler code here
	mouse3.x = 0;
	mouse_last3.x = 0;
	mouse3.y = 0;
	mouse_last3.y = 0;

	click3 = 0;
}


void Surprise::OnBnClickedRecording()
{
	// TODO: Add your control notification handler code here

	record3 = 1;
	//AllocConsole();
	//freopen("CONOUT$", "w+t", stdout);
	//cout << j % 200 << endl;

	//while (record==1 && j%200==0)
	//{
	//Face_ROI(mouse,mouse_last);


	//write frame to Angry File
	//while (record)
	//{
	Face_ROI3(mouse3, mouse_last3);


	//write frame to Angry File
	char c[20];
	String buf1, buf2, buf3;
	buf1 = "Surprise//";
	buf2 = _itoa(i3, c, 10);
	buf3 = ".bmp";
	buf1 = buf1 + buf2 + buf3;

	//open console to test result of buf1
	//	AllocConsole();
	//	freopen("CONOUT$", "w+t", stdout);


	Rect rect(mouse_test03.x, mouse_test03.y, 200, 220);
	Mat image = frame3(rect);
	Mat image_dst;
	cvtColor(image, image_dst, CV_BGR2GRAY);

	imwrite(buf1, image_dst);
	i3++;
	if (i3 == 200)
	{
		Collected dialog_test;

		dialog_test.DoModal();

		//break;
	}

	//}

}
