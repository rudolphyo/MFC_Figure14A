#pragma once


// CDlgNewProperties dialog

class CDlgNewProperties : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNewProperties)

public:
	CDlgNewProperties(double m_A = 4.0, double m_A1 = 1.0, double m_A2 = 1.0, double m_A3 = 1.0, CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgNewProperties();

// Dialog Data
	enum { IDD = IDD_NEWPROPERTIES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	// variable for editing side of square A
	double m_A;
	afx_msg void OnEnChangeEditA();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	// for editing radius of A1
	double m_A1;
	// for editing radius A2
	double m_A2;
	// for editing radius of A3
	double m_A3;
};
