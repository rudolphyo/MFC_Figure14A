// DlgNewProperties.cpp : implementation file
//

#include "stdafx.h"
#include "Figure14A.h"
#include "DlgNewProperties.h"
#include "afxdialogex.h"
#include <vector>


// CDlgNewProperties dialog

IMPLEMENT_DYNAMIC(CDlgNewProperties, CDialogEx)

CDlgNewProperties::CDlgNewProperties(double side_A, double side_A1, double side_A2, double side_A3, CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgNewProperties::IDD, pParent)
	, m_A(side_A)
	, m_A1(side_A1)
	, m_A2(side_A2)
	, m_A3(side_A3)
{

}

CDlgNewProperties::~CDlgNewProperties()
{
}

void CDlgNewProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT_A, m_A);
	//DDV_MinMaxDouble(pDX, m_A, 5, 1000);
	//DDX_Text(pDX, ID_EDIT_A1, m_A1);
	//DDX_Text(pDX, ID_EDIT_A2, m_A2);
	//DDX_Text(pDX, ID_EDIT_A3, m_A3);
}

BEGIN_MESSAGE_MAP(CDlgNewProperties, CDialogEx)
	//ON_BN_CLICKED(IDOK, &CDlgNewProperties::OnBnClickedOk)
	//ON_EN_CHANGE(IDC_EDIT_A, &CDlgNewProperties::OnEnChangeEditA)
END_MESSAGE_MAP()


// CDlgNewProperties message handlers

//BOOL CDlgNewProperties::OnInitDialog() {
//	CDialogEx::OnInitDialog();
//	CEdit *pEdit = (CEdit*)GetDlgItem(ID_EDIT_A);
//	CString str;
//	str
//}

void CDlgNewProperties::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CDlgNewProperties::OnEnChangeEditA()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


BOOL CDlgNewProperties::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CEdit *pEdit = (CEdit *)GetDlgItem(ID_EDIT_A);
	CString str;
	str.Format(_T("%f"), m_A);
	(*pEdit).SetWindowText(str);

	pEdit = (CEdit *)GetDlgItem(ID_EDIT_A1);
	str.Format(_T("%f"), m_A1);
	(*pEdit).SetWindowText(str);

	pEdit = (CEdit *)GetDlgItem(ID_EDIT_A2);
	str.Format(_T("%f"), m_A2);
	(*pEdit).SetWindowText(str);

	pEdit = (CEdit *)GetDlgItem(ID_EDIT_A3);
	str.Format(_T("%f"), m_A3);
	(*pEdit).SetWindowText(str);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgNewProperties::OnOK()
{
	CEdit *pEDitA = (CEdit *)GetDlgItem(ID_EDIT_A);
	CEdit *pEDitA1 = (CEdit *)GetDlgItem(ID_EDIT_A1);
	CEdit *pEDitA2 = (CEdit *)GetDlgItem(ID_EDIT_A2);
	CEdit *pEDitA3 = (CEdit *)GetDlgItem(ID_EDIT_A3);

	CString strA, strA1, strA2, strA3;
	
	(*pEDitA).GetWindowText(strA);
	m_A = _wtof(strA);
	
	(*pEDitA1).GetWindowText(strA1);
	m_A1 = _wtof(strA1);
	
	(*pEDitA2).GetWindowText(strA2);
	m_A2 = _wtof(strA2);

	(*pEDitA3).GetWindowText(strA3);
	m_A3 = _wtof(strA3);
	
	CDialogEx::OnOK();
}
