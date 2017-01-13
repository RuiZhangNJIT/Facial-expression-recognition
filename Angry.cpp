// Angry.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FacialExpression.h"
#include "Angry.h"
#include "afxdialogex.h"
#include "Collected.h"


#include<opencv2\opencv.hpp>
#include <stdlib.h>


using namespace cv;
using namespace std;
// Angry dialog

IMPLEMENT_DYNAMIC(Angry, CDialogEx)

Angry::Angry(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Angry, pParent)
{

}

Angry::~Angry()
{
}

void Angry::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Angry, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Angry::OnBnClickedClearMouse)
	ON_BN_CLICKED(IDC_BUTTON2, &Angry::OnBnClickedRecording)
	ON_BN_CLICKED(IDC_BUTTON3, &Angry::OnBnClickedEnd)
	ON_BN_CLICKED(IDC_BUTTON4, &Angry::OnBnClickedOpenCamera)
END_MESSAGE_MAP()


// Angry message handlers
//VideoCapture capture(0);
Mat frame;
int tag = 0;
int record = 0;
int click = 0;
//mouse click the face area

Point l_start;
Point l_end;
Point mouse=(0,0);
Point mouse_last=(0,0);
int width;
int height;
int i = 0;
int j = 0;

Point mouse_test=(0,0);
Point mouse_test1 = (0, 0);

//face area(ROI) function
void Face_ROI(Point Begin, Point Finished)
  {
 
	// caculate width & height
	width = Begin.x - Finished.x;
	height = Begin.y - Finished.y;
	//rectangle(src, start, center, Scalar(255, 0, 0));
   }

void Face_ROI_test(Point Begin)
{
	width = 200;
	height = 220;
	mouse_test.x = Begin.x;
	mouse_test.y = Begin.y - 100;
	mouse_test1.x = mouse_test.x + width;
	mouse_test1.y = mouse_test.y + height;

 }

//mouse click function

void OnMouseAction(int event, int x, int y, int flags, void *ustc)
{


	if (event == CV_EVENT_LBUTTONDOWN)
	{
		//cout << "hehe" << endl;
		mouse.x = x;
		mouse.y = y;
		click++;
	 }


}


void Angry::OnBnClickedOpenCamera()
{
	// TODO: Add your control notification handler code here
	//cvNamedWindow("Readvideo", 1);
	VideoCapture capture(0);
	while (1)
	{
		capture >> frame;
		
		if (record == 1)
		{
			j++;
		}

    //click mouse
		setMouseCallback("ReadVideo", OnMouseAction);

		circle(frame, mouse, 5, Scalar(0, 0, 255), 2);
		//circle(frame, mouse_last, 5, Scalar(0, 0, 255), 2);
		Face_ROI_test(mouse);
		circle(frame,mouse_test,5,Scalar(0,0,255),2);
		circle(frame,mouse_test1,5,Scalar(0,0,255),2);
		rectangle(frame, mouse_test, mouse_test1, Scalar(255, 0, 0));
		

   //show the images

		imshow("ReadVideo", frame);

	//make sure the click point won`t disappear

		 if (click < 2)
		{
			mouse_last = mouse;
		}

		// if (record == 1 && j%200==0)
		 //{
			// OnBnClickedRecording();
		 //}

		 //AllocConsole();
		 //freopen("CONOUT$", "w+t", stdout);
		 if (j % 3 == 0 && record== 1)
		 {
			 //cout <<j<< "=j is equal 0" << endl;
			 OnBnClickedRecording();
		 }
		 if (i == 200)
		 {
			 capture.release();
			 break;

		 }

        
		waitKey(30);

		
	}
}

void Angry::OnBnClickedClearMouse()
{
	// TODO: Add your control notification handler code here

	mouse.x = 0;
	mouse_last.x = 0;
	mouse.y = 0;
	mouse_last.y = 0;
	
	click = 0;

}


void Angry::OnBnClickedRecording()
{
	// TODO: Add your control notification handler code here
	record = 1;
	//AllocConsole();
	//freopen("CONOUT$", "w+t", stdout);
	//cout << j % 200 << endl;

	//while (record==1 && j%200==0)
	//{
		//Face_ROI(mouse,mouse_last);


		//write frame to Angry File
	//while (record)
	//{
		Face_ROI(mouse, mouse_last);


		//write frame to Angry File
		char c[20];
		String buf1, buf2, buf3;
		buf1 = "Angry//";
		buf2 = _itoa(i, c, 10);
		buf3 = ".bmp";
		buf1 = buf1 + buf2 + buf3;

		//open console to test result of buf1
		//	AllocConsole();
		//	freopen("CONOUT$", "w+t", stdout);


		Rect rect(mouse_test.x, mouse_test.y, 200, 220);
		Mat image = frame(rect);
		Mat image_dst;
		cvtColor(image, image_dst, CV_BGR2GRAY);

		imwrite(buf1, image_dst);
		i++;
		if (i == 200)
		{
			Collected dialog_test;

			dialog_test.DoModal();

			//break;
		}

	//}
		
		
}


void Angry::OnBnClickedEnd()
{
	// TODO: Add your control notification handler code here
	record = 0;
}



