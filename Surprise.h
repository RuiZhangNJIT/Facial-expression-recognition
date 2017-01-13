#pragma once


// Surprise dialog

class Surprise : public CDialogEx
{
	DECLARE_DYNAMIC(Surprise)

public:
	Surprise(CWnd* pParent = NULL);   // standard constructor
	virtual ~Surprise();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Surpurise };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedMouseClear();
	afx_msg void OnBnClickedRecording();
};
