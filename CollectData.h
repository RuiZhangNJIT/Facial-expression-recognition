#pragma once


// CollectData dialog

class CollectData : public CDialogEx
{
	DECLARE_DYNAMIC(CollectData)

public:
	CollectData(CWnd* pParent = NULL);   // standard constructor
	virtual ~CollectData();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COLLECTDATA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAngry();
	afx_msg void OnBnClickedHappy();
	afx_msg void OnBnClickedNeural();
	afx_msg void OnBnClickedSuprise();
};
