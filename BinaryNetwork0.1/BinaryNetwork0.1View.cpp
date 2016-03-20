
// BinaryNetwork0.1View.cpp : implementation of the CBinaryNetwork01View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BinaryNetwork0.1.h"
#endif

#include "BinaryNetwork0.1Doc.h"
#include "BinaryNetwork0.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBinaryNetwork01View

IMPLEMENT_DYNCREATE(CBinaryNetwork01View, CView)

BEGIN_MESSAGE_MAP(CBinaryNetwork01View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CBinaryNetwork01View construction/destruction

CBinaryNetwork01View::CBinaryNetwork01View()
{
	// TODO: add construction code here

}

CBinaryNetwork01View::~CBinaryNetwork01View()
{
}

BOOL CBinaryNetwork01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CBinaryNetwork01View drawing

void CBinaryNetwork01View::OnDraw(CDC* pDC)
{
	CBinaryNetwork01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	COLORREF white = RGB(255, 255, 255);
	COLORREF grey = RGB(200, 200, 200);
	COLORREF darkgrey = RGB(100, 100, 100);
	COLORREF darkergrey = RGB(70, 70, 70);
	int nodeHeight = 50;
	int nodeWidth = 50;

	//int nDCSave = pDC->SaveDC();
	CRect rcClient;
	GetClientRect(&rcClient);

	pDC->FillSolidRect(&rcClient, darkergrey);
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC->SelectObject(&br);

	int col = int(sqrt(pDoc->getCellNum()));
	int row = int(pDoc->getCellNum() / col);
	int rowplus = row + 1;
	int colplus = pDoc->getCellNum() - row*col;
	for (int irow = 0; irow < row; irow++)
	{
		for (int icol = 0; icol < col; icol++)
		{
			CRect nodeShow;
			nodeShow.top = irow * nodeHeight;
			nodeShow.left = icol * nodeWidth;
			nodeShow.right = nodeShow.left + nodeWidth;
			nodeShow.bottom = nodeShow.top + nodeHeight;
			if (pDoc->getCellVal(col*irow + icol)) {
				pDC->FillSolidRect(&nodeShow, grey);
			}
			else {
				pDC->FillSolidRect(&nodeShow, darkergrey);
			}
			pDC->Rectangle(&nodeShow);
		}
	}
	//code for rowplus needed here.

	int max = pDoc->getWorldMax();
	for (int irow = -max; irow <= max; irow++)
	{
		for (int icol = -max; icol <= max; icol++)
		{
			CRect worldShow;
			int cellSize = pDoc->getCellSize();
			worldShow.top = 450 - icol * cellSize;
			worldShow.left = 1100 + irow * cellSize;
			worldShow.right = worldShow.left + cellSize;
			worldShow.bottom = worldShow.top + cellSize;
			if (pDoc->getWorldVal(irow, icol)) {
				pDC->FillSolidRect(&worldShow, grey);
			}
			else {
				pDC->FillSolidRect(&worldShow, darkergrey);
			}
			pDC->Rectangle(&worldShow);
		}
	}

	CRect cellShow;
	int cellSize = pDoc->getCellSize();
	cellShow.top = 450 - cellSize * pDoc->cellY();
	cellShow.left = 1100 + cellSize  *pDoc->cellX();
	cellShow.right = cellShow.left + cellSize;
	cellShow.bottom = cellShow.top + cellSize;
	pDC->FillSolidRect(&cellShow, white);
	pDC->Rectangle(&cellShow);

	//pDC->RestoreDC(nDCSave);
	br.DeleteObject();
}

void CBinaryNetwork01View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBinaryNetwork01View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBinaryNetwork01View diagnostics

#ifdef _DEBUG
void CBinaryNetwork01View::AssertValid() const
{
	CView::AssertValid();
}

void CBinaryNetwork01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBinaryNetwork01Doc* CBinaryNetwork01View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBinaryNetwork01Doc)));
	return (CBinaryNetwork01Doc*)m_pDocument;
}
#endif //_DEBUG


// CBinaryNetwork01View message handlers


void CBinaryNetwork01View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CBinaryNetwork01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	const int step = 100;
	for (int istep = 0; istep < step; istep++) {
		pDoc->Run();

		CRect cellNeighbor;
		int cellSize = pDoc->getCellSize();
		cellNeighbor.top = 450 - cellSize*pDoc->cellY() - cellSize;
		cellNeighbor.left = 1100 + cellSize*pDoc->cellX() - cellSize;
		cellNeighbor.right = cellNeighbor.left + 3 * cellSize;
		cellNeighbor.bottom = cellNeighbor.top + 3 * cellSize;

		CRect brainArea;
		brainArea.top = 0;
		brainArea.bottom = 500;
		brainArea.left = 0;
		brainArea.right = 500;


		InvalidateRect(&cellNeighbor);
		InvalidateRect(&brainArea);
		UpdateWindow();
		//Sleep(100);
	}

	CView::OnLButtonDown(nFlags, point);
}


void CBinaryNetwork01View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CBinaryNetwork01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->Run();

	CRect cellNeighbor;
	int cellSize = pDoc->getCellSize();
	cellNeighbor.top = 400 - cellSize*pDoc->cellY() - cellSize;
	cellNeighbor.left = 1100 + cellSize*pDoc->cellX() - cellSize;
	cellNeighbor.right = cellNeighbor.left + 3 * cellSize;
	cellNeighbor.bottom = cellNeighbor.top + 3 * cellSize;

	CRect brainArea;
	brainArea.top = 0;
	brainArea.bottom = 500;
	brainArea.left = 0;
	brainArea.right = 500;

	InvalidateRect(&cellNeighbor);
	InvalidateRect(&brainArea);
	UpdateWindow();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
