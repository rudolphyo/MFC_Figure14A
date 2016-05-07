
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Figure14A.h"
#include "ChildView.h"
#include "2DPoint.h"
#include "My2DObject14.h"
#include "DlgNewProperties.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CChildView::CChildView() {
	m_nCatched = -1;
}

CChildView::~CChildView()
{
	//for (std::vector<CMy2DObject14*>::iterator &it = myFigures.begin; it != &myFigures.end; ++it) {
		//delete &it;
	//}

	for (int i = 0; i < myFigures.size(); i++) {
		delete myFigures[i];
	}
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_NEWFIGURE, OnNewFigure)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CDC dcMem;
	CRect rect;
	CBitmap bmp;

	dcMem.CreateCompatibleDC(&dc);
	GetClientRect(&rect);
	bmp.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	CBitmap *pOldBmp = dcMem.SelectObject(&bmp);
	dcMem.FillSolidRect(0, 0, rect.Width(), rect.Height(), 0xFFFFFF);

	for (int i = 0; i < myFigures.size(); i++) {
		(*myFigures[i]).Draw(dcMem);
	}

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);
	dcMem.SelectObject(pOldBmp);
}

int CChildView::FindObjects(CPoint point) {
	int nFigures = -1;
	for (int i = myFigures.size() - 1; i >= 0; i--) {
		if ((*myFigures[i]).IsInside(point.x, point.y)) {
			nFigures = i;
			break;
		}
	}
	return nFigures;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_nCatched = FindObjects(point);

	if (m_nCatched >= 0) {
		m_MousePos = point;
		SetCapture();
	}

	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_nCatched = -1;
	ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_nCatched >= 0) {
		CRect rect;
		GetClientRect(&rect);
		point.x = min(rect.right, max(rect.left, point.x));
		point.y = min(rect.bottom, max(rect.top, point.y));
		CPoint Delta = point - m_MousePos;
		myFigures[m_nCatched]->Move(Delta.x, Delta.y, 0);
		m_MousePos = point;
		Invalidate();
		UpdateWindow();
	}
	CWnd::OnMouseMove(nFlags, point);
}

void CChildView::OnNewFigure() {
	CRect rect;
	GetClientRect(&rect);
	myFigures.push_back(new CMy2DObject14(200, 40, 40, 40, 0, CMy2DPoint(rand()%rect.Width(), rand()%rect.Height())));
	Invalidate();
}




BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return true;
}


void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	m_nCatched = FindObjects(point);

	if (m_nCatched >= 0) {

		CDlgNewProperties DlgA((*myFigures[m_nCatched]).GetA());
		CDlgNewProperties DlgA1((*myFigures[m_nCatched]).GetA1());
		CDlgNewProperties DlgA2((*myFigures[m_nCatched]).GetA2());
		CDlgNewProperties DlgA3((*myFigures[m_nCatched]).GetA3());

		if (DlgA.DoModal()){
			(*myFigures[m_nCatched]).SetA(DlgA.m_A);
			(*myFigures[m_nCatched]).SetA1(DlgA.m_A1);
			(*myFigures[m_nCatched]).SetA2(DlgA.m_A2);
			(*myFigures[m_nCatched]).SetA3(DlgA.m_A3);
			Invalidate();
		}


	}
	CWnd::OnLButtonDblClk(nFlags, point);
}