#pragma once


// Angry dialog

class Angry : public CDialogEx
{
	DECLARE_DYNAMIC(Angry)

public:
	Angry(CWnd* pParent = NULL);   // standard constructor
	virtual ~Angry();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClearMouse();
	afx_msg void OnBnClickedRecording();
	afx_msg void OnBnClickedEnd();
	afx_msg void OnBnClickedOpenCamera();
};
