
// MFC_FacialExpression.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_FacialExpressionApp:
// See MFC_FacialExpression.cpp for the implementation of this class
//

class CMFC_FacialExpressionApp : public CWinApp
{
public:
	CMFC_FacialExpressionApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_FacialExpressionApp theApp;