#pragma once


// Testing dialog

class Testing : public CDialogEx
{
	DECLARE_DYNAMIC(Testing)

public:
	Testing(CWnd* pParent = NULL);   // standard constructor
	virtual ~Testing();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenCamera();
	afx_msg void OnBnClickedMouseClear();
	afx_msg void OnBnClickedTesting();
};
