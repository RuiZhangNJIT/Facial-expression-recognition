#pragma once


// Neutral dialog

class Neutral : public CDialogEx
{
	DECLARE_DYNAMIC(Neutral)

public:
	Neutral(CWnd* pParent = NULL);   // standard constructor
	virtual ~Neutral();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_neutral };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedRecording();
};
