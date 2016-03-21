
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

void CBinaryNetwork01View::singleCell(std::list<Cell*>::iterator iCell)
{
	CBinaryNetwork01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	const int step = 100;
	for (int istep = 0; istep < step; istep++) {
		pDoc->runAll();

		CRect cellNeighbor;
		cellNeighbor.top = 450 - cellSize*pDoc->cellY(iCell) - cellSize;
		cellNeighbor.left = 1100 + cellSize*pDoc->cellX(iCell) - cellSize;
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
}

void CBinaryNetwork01View::showBrain(std::list<Cell*>::iterator iCell)
{
	//to be added.
}

void CBinaryNetwork01View::multipleCell(CDC * pDC, CBinaryNetwork01Doc * pDoc)
{
	drawWorld(pDC, pDoc, pDoc->getSampleWorld());
	for (std::list<Cell*>::iterator iCell = pDoc->getCellHead(); iCell != pDoc->getCellEnd(); ++iCell) {
		drawCell(pDC, pDoc, iCell);
	}
}

void CBinaryNetwork01View::drawBrain(CDC* pDC, CBinaryNetwork01Doc* pDoc, std::list<Cell*>::iterator iCell)
{
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC->SelectObject(&br);

	int col = int(sqrt(pDoc->getCellNum(iCell)));
	int row = int(pDoc->getCellNum(iCell) / col);
	int rowplus = row + 1;
	int colplus = pDoc->getCellNum(iCell) - row*col;
	for (int irow = 0; irow < row; irow++)
	{
		for (int icol = 0; icol < col; icol++)
		{
			CRect nodeShow;
			nodeShow.top = irow * nodeHeight;
			nodeShow.left = icol * nodeWidth;
			nodeShow.right = nodeShow.left + nodeWidth;
			nodeShow.bottom = nodeShow.top + nodeHeight;
			if (pDoc->getCellVal(iCell, col*irow + icol)) {
				pDC->FillSolidRect(&nodeShow, grey);
			}
			else {
				pDC->FillSolidRect(&nodeShow, darkergrey);
			}
			pDC->Rectangle(&nodeShow);
		}
	}
	//code for rowplus needed here.

	br.DeleteObject();
}

void CBinaryNetwork01View::drawCell(CDC * pDC, CBinaryNetwork01Doc * pDoc, std::list<Cell*>::iterator iCell)
{
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC->SelectObject(&br);

	CRect cellShow;
	cellShow.top = 450 - cellSize * pDoc->cellY(iCell);
	cellShow.left = 1100 + cellSize  *pDoc->cellX(iCell);
	cellShow.right = cellShow.left + cellSize;
	cellShow.bottom = cellShow.top + cellSize;
	pDC->FillSolidRect(&cellShow, white);
	pDC->Rectangle(&cellShow);

	br.DeleteObject();
}

void CBinaryNetwork01View::drawWorld(CDC * pDC, CBinaryNetwork01Doc * pDoc, World* sample)
{
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC->SelectObject(&br);

	int max = pDoc->getWorldMax(sample);
	for (int irow = -max; irow <= max; irow++)
	{
		for (int icol = -max; icol <= max; icol++)
		{
			CRect worldShow;
			worldShow.top = 450 - icol * cellSize;
			worldShow.left = 1100 + irow * cellSize;
			worldShow.right = worldShow.left + cellSize;
			worldShow.bottom = worldShow.top + cellSize;
			if (pDoc->getWorldVal(sample, irow, icol)) {
				pDC->FillSolidRect(&worldShow, grey);
			}
			else {
				pDC->FillSolidRect(&worldShow, darkergrey);
			}
			pDC->Rectangle(&worldShow);
		}
	}

	br.DeleteObject();
}

void CBinaryNetwork01View::drawWorld(CDC * pDC, CBinaryNetwork01Doc * pDoc, std::list<World*>::iterator iWorld)
{
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC->SelectObject(&br);

	int max = pDoc->getWorldMax(iWorld);
	for (int irow = -max; irow <= max; irow++)
	{
		for (int icol = -max; icol <= max; icol++)
		{
			CRect worldShow;
			worldShow.top = 450 - icol * cellSize;
			worldShow.left = 1100 + irow * cellSize;
			worldShow.right = worldShow.left + cellSize;
			worldShow.bottom = worldShow.top + cellSize;
			if (pDoc->getWorldVal(iWorld, irow, icol)) {
				pDC->FillSolidRect(&worldShow, grey);
			}
			else {
				pDC->FillSolidRect(&worldShow, darkergrey);
			}
			pDC->Rectangle(&worldShow);
		}
	}

	br.DeleteObject();
}

void CBinaryNetwork01View::OnDraw(CDC* pDC)
{
	CBinaryNetwork01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//int nDCSave = pDC->SaveDC();
	CRect rcClient;
	GetClientRect(&rcClient);
	pDC->FillSolidRect(&rcClient, darkergrey);

	multipleCell(pDC, pDoc);

	//drawBrain(pDC, pDoc);
	//drawWorld(pDC, pDoc);
	//drawCell(pDC, pDoc);

	//pDC->RestoreDC(nDCSave);
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
	CBinaryNetwork01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int day = 1;
	while (pDoc->getLabNum() > 5) {
		pDoc->runAll();
		if (day % pDoc->reproDay == 0) {
			pDoc->reproduce();
		}

		//CRect worldSpace;
		//worldSpace.top = 450 - cellSize * 40;
		//worldSpace.left = 1100 - cellSize * 40;
		//worldSpace.right = worldSpace.left + 81 * cellSize;
		//worldSpace.bottom = worldSpace.top + 81 * cellSize;

		CRect shortWorldSpace;
		shortWorldSpace.top = 450 - cellSize * 15;
		shortWorldSpace.left = 1100 - cellSize * 15;
		shortWorldSpace.right = shortWorldSpace.left + 31 * cellSize;
		shortWorldSpace.bottom = shortWorldSpace.top + 31 * cellSize;

		InvalidateRect(&shortWorldSpace);
		UpdateWindow();
		day++;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CBinaryNetwork01View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CBinaryNetwork01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->runAll();

	CRect worldSpace;
	worldSpace.top = 450 - cellSize*40;
	worldSpace.left = 1100 - cellSize*40;
	worldSpace.right = worldSpace.left + 81*cellSize;
	worldSpace.bottom = worldSpace.top + 81*cellSize;

	InvalidateRect(&worldSpace);
	UpdateWindow();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
