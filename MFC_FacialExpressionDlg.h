
// MFC_FacialExpressionDlg.h : header file
//

#pragma once


// CMFC_FacialExpressionDlg dialog
class CMFC_FacialExpressionDlg : public CDialogEx
{
// Construction
public:
	CMFC_FacialExpressionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_FACIALEXPRESSION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCollectData();
	afx_msg void OnBnClickedTraining();
	afx_msg void OnBnClickedTesting();
};
