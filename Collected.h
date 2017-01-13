#pragma once


// Collected dialog

class Collected : public CDialogEx
{
	DECLARE_DYNAMIC(Collected)

public:
	Collected(CWnd* pParent = NULL);   // standard constructor
	virtual ~Collected();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CollectFinished };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
