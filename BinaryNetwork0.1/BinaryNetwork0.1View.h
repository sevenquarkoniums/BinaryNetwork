
// BinaryNetwork0.1View.h : interface of the CBinaryNetwork01View class
//

#pragma once


class CBinaryNetwork01View : public CView
{
protected: // create from serialization only
	CBinaryNetwork01View();
	DECLARE_DYNCREATE(CBinaryNetwork01View)

// Attributes
public:
	CBinaryNetwork01Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CBinaryNetwork01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in BinaryNetwork0.1View.cpp
inline CBinaryNetwork01Doc* CBinaryNetwork01View::GetDocument() const
   { return reinterpret_cast<CBinaryNetwork01Doc*>(m_pDocument); }
#endif

