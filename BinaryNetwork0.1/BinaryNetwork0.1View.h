
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

	COLORREF white = RGB(255, 255, 255);
	COLORREF grey = RGB(200, 200, 200);
	COLORREF darkgrey = RGB(100, 100, 100);
	COLORREF darkergrey = RGB(70, 70, 70);
	int nodeHeight = 50;
	int nodeWidth = 50;
	int cellSize = 10;

// Operations
public:
	//update brainArea for a single cell. Number of steps defined here.
	void singleCell(std::list<Cell*>::iterator iCell);
	//to be added.
	void showBrain(std::list<Cell*>::iterator iCell);
	//drawCell() and drawWorld()
	void multipleCell(CDC * pDC, CBinaryNetwork01Doc * pDoc);
	//draw a single brain.
	void drawBrain(CDC* pDC, CBinaryNetwork01Doc* pDoc, std::list<Cell*>::iterator iCell);
	//draw a single cell.
	void drawCell(CDC* pDC, CBinaryNetwork01Doc* pDoc, std::list<Cell*>::iterator iCell);
	//draw the sample world.
	void drawWorld(CDC * pDC, CBinaryNetwork01Doc * pDoc, World* sample);
	void drawWorld(CDC* pDC, CBinaryNetwork01Doc* pDoc, std::list<World*>::iterator iWorld);

// Overrides
public:
	//OnDraw is called at beginning and every time updateWindow().
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

