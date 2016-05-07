
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "My2DObject14.h"
#include "2DPoint.h"
#include <vector>



// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
protected:
	//CMy2DObject14 myFigure;
	std::vector<CMy2DObject14 *> myFigures;
	//bool m_bCatched;
	int m_nCatched;
	CPoint m_MousePos;

	//If the point is inside of a circle,
	//the function will return its number, otherwise -1
	int FindObjects(CPoint point);
// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnNewFigure();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

