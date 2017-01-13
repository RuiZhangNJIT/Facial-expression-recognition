// Collected.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FacialExpression.h"
#include "Collected.h"
#include "afxdialogex.h"


// Collected dialog

IMPLEMENT_DYNAMIC(Collected, CDialogEx)

Collected::Collected(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CollectFinished, pParent)
{

}

Collected::~Collected()
{
}

void Collected::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Collected, CDialogEx)
END_MESSAGE_MAP()


// Collected message handlers
