// CollectData.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FacialExpression.h"
#include "CollectData.h"
#include "afxdialogex.h"
#include <opencv2\opencv.hpp>
#include "Angry.h"
#include "Happy.h"
#include "Neutral.h"
#include "Surprise.h"
// CollectData dialog

using namespace cv;


IMPLEMENT_DYNAMIC(CollectData, CDialogEx)

CollectData::CollectData(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_COLLECTDATA, pParent)
{

}

CollectData::~CollectData()
{
}

void CollectData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CollectData, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CollectData::OnBnClickedAngry)
	ON_BN_CLICKED(IDC_BUTTON5, &CollectData::OnBnClickedHappy)
	ON_BN_CLICKED(IDC_BUTTON4, &CollectData::OnBnClickedNeural)
	ON_BN_CLICKED(IDC_BUTTON6, &CollectData::OnBnClickedSuprise)
END_MESSAGE_MAP()


// CollectData message handlers


void CollectData::OnBnClickedAngry()
{
	// TODO: Add your control notification handler code here
	//VideoCapture capture(0);
	Angry dialog_test;

	dialog_test.DoModal();
	

	
	
}


void CollectData::OnBnClickedHappy()
{
	// TODO: Add your control notification handler code here
	Happy dialog_test;

	dialog_test.DoModal();
}


void CollectData::OnBnClickedNeural()
{
	// TODO: Add your control notification handler code here
	Neutral dialog_test;

	dialog_test.DoModal();
}


void CollectData::OnBnClickedSuprise()
{
	// TODO: Add your control notification handler code here
	Surprise dialog_test;

	dialog_test.DoModal();
}
