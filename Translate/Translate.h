
// Translate.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTranslateApp:
// See Translate.cpp for the implementation of this class
//

class CTranslateApp : public CWinApp
{
public:
	CTranslateApp();

// Overrides
public:
	virtual BOOL InitInstance();

	const static int COL = 11;
	const static int ROW = 2;
	CString arrWords[ROW][COL] = { { _T("Български"), _T("Куче"), _T("Котка"), _T("Мравка"), _T("Мишка"), _T("Лъв"), _T("Крава"), _T("Жираф"), _T("Слон"), _T("Косатка"), _T("Кокошка")},
	{ _T("English"), _T("Dog"), _T("Cat"), _T("Ant"), _T("Mouse"), _T("Lion"), _T("Cow"), _T("Jiraffe"), _T("Elephant"), _T("Killer whale"), _T("Chicken")} };

	CString m_csConfig = _T("");

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTranslateApp theApp;
