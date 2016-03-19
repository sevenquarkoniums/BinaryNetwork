
// BinaryNetwork0.1.h : main header file for the BinaryNetwork0.1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CBinaryNetwork01App:
// See BinaryNetwork0.1.cpp for the implementation of this class
//

class CBinaryNetwork01App : public CWinAppEx
{
public:
	CBinaryNetwork01App();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBinaryNetwork01App theApp;
