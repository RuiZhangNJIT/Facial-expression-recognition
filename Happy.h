#pragma once


// Happy dialog

class Happy : public CDialogEx
{
	DECLARE_DYNAMIC(Happy)

public:
	Happy(CWnd* pParent = NULL);   // standard constructor
	virtual ~Happy();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Happy };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedClearMouse();
	afx_msg void OnBnClickedRecording();
};
