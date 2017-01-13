// Happy.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FacialExpression.h"
#include "Happy.h"
#include "afxdialogex.h"
#include "Collected.h"


#include<opencv2\opencv.hpp>
#include <stdlib.h>
using namespace cv;
using namespace std;

// Happy dialog

IMPLEMENT_DYNAMIC(Happy, CDialogEx)

Happy::Happy(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Happy, pParent)
{

}

Happy::~Happy()
{
}

void Happy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Happy, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Happy::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_BUTTON2, &Happy::OnBnClickedClearMouse)
	ON_BN_CLICKED(IDC_BUTTON3, &Happy::OnBnClickedRecording)
END_MESSAGE_MAP()


// Happy message handlers

//VideoCapture capture1(0);
Mat frame1;
int tag1 = 0;
int record1 = 0;
int click1 = 0;
//mouse click the face area

Point l_start1;
Point l_end1;
Point mouse1 = (0, 0);
Point mouse_last1 = (0, 0);
int width1;
int height1;
int i1 = 0;
int j6 = 0;

Point mouse_test10 = (0, 0);
Point mouse_test11 = (0, 0);

//face area(ROI) function
void Face_ROI1(Point Begin, Point Finished)
{

	// caculate width & height
	width1 = Begin.x - Finished.x;
	height1 = Begin.y - Finished.y;
	//rectangle(src, start, center, Scalar(255, 0, 0));
}

void Face_ROI_test1(Point Begin)
{
	width1 = 200;
	height1 = 220;
	mouse_test10.x = Begin.x;
	mouse_test10.y = Begin.y - 100;
	mouse_test11.x = mouse_test10.x + width1;
	mouse_test11.y = mouse_test10.y + height1;

}
//mouse click function

void OnMouseAction1(int event, int x, int y, int flags, void *ustc)
{


	if (event == CV_EVENT_LBUTTONDOWN)
	{
		//cout << "hehe" << endl;
		mouse1.x = x;
		mouse1.y = y;
		click1++;
	}


}


void Happy::OnBnClickedOpen()
{
	// TODO: Add your control notification handler code here
	VideoCapture capture1(0);
	while (1)
	{
		capture1 >> frame1;

		if (record1 == 1)
		{
			j6++;
		}

		//click mouse
		setMouseCallback("ReadVideo", OnMouseAction1);

		circle(frame1, mouse1, 5, Scalar(0, 0, 255), 2);
		//circle(frame, mouse_last, 5, Scalar(0, 0, 255), 2);
		Face_ROI_test1(mouse1);
		circle(frame1, mouse_test10, 5, Scalar(0, 0, 255), 2);
		circle(frame1, mouse_test11, 5, Scalar(0, 0, 255), 2);
		rectangle(frame1, mouse_test10, mouse_test11, Scalar(255, 0, 0));


		//show the images

		imshow("ReadVideo", frame1);

		//make sure the click point won`t disappear

		if (click1 < 2)
		{
			mouse_last1 = mouse1;
		}

		// if (record == 1 && j%200==0)
		//{
		// OnBnClickedRecording();
		//}

		//AllocConsole();
		//freopen("CONOUT$", "w+t", stdout);
		if (j6 % 3 == 0 && record1 == 1)
		{
			//cout <<j<< "=j is equal 0" << endl;
			OnBnClickedRecording();
		}
		if (i1 == 200)
		{
			capture1.release();
			break;

		}


		waitKey(30);


	}
}


void Happy::OnBnClickedClearMouse()
{
	// TODO: Add your control notification handler code here

	mouse1.x = 0;
	mouse_last1.x = 0;
	mouse1.y = 0;
	mouse_last1.y = 0;

	click1 = 0;
}


void Happy::OnBnClickedRecording()
{
	// TODO: Add your control notification handler code here
	record1 = 1;
	//AllocConsole();
	//freopen("CONOUT$", "w+t", stdout);
	//cout << j % 200 << endl;

	//while (record==1 && j%200==0)
	//{
	//Face_ROI(mouse,mouse_last);


	//write frame to Angry File
	//while (record)
	//{
	Face_ROI1(mouse1, mouse_last1);


	//write frame to Angry File
	char c[20];
	String buf1, buf2, buf3;
	buf1 = "Happy//";
	buf2 = _itoa(i1, c, 10);
	buf3 = ".bmp";
	buf1 = buf1 + buf2 + buf3;

	//open console to test result of buf1
	//	AllocConsole();
	//	freopen("CONOUT$", "w+t", stdout);


	Rect rect(mouse_test10.x, mouse_test10.y, 200, 220);
	Mat image = frame1(rect);
	Mat image_dst;
	cvtColor(image, image_dst, CV_BGR2GRAY);

	imwrite(buf1, image_dst);
	i1++;
	if (i1 == 200)
	{
		Collected dialog_test;

		dialog_test.DoModal();

		//break;
	}

	//}
}
