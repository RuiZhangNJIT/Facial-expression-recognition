#pragma once


// Training dialog

class Training : public CDialogEx
{
	DECLARE_DYNAMIC(Training)

public:
	Training(CWnd* pParent = NULL);   // standard constructor
	virtual ~Training();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Traning };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAngry();
	afx_msg void OnBnClickedHappy();
	afx_msg void OnBnClickedNeutral();
	afx_msg void OnBnClickedSuprise();
};
