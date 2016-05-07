
// Figure14A.h : main header file for the Figure14A application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFigure14AApp:
// See Figure14A.cpp for the implementation of this class
//

class CFigure14AApp : public CWinApp
{
public:
	CFigure14AApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFigure14AApp theApp;
