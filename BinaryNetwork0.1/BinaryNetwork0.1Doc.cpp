
// BinaryNetwork0.1Doc.cpp : implementation of the CBinaryNetwork01Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BinaryNetwork0.1.h"
#endif

#include "BinaryNetwork0.1Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CBinaryNetwork01Doc

IMPLEMENT_DYNCREATE(CBinaryNetwork01Doc, CDocument)

BEGIN_MESSAGE_MAP(CBinaryNetwork01Doc, CDocument)
END_MESSAGE_MAP()


// CBinaryNetwork01Doc construction/destruction

CBinaryNetwork01Doc::CBinaryNetwork01Doc()
{
	// TODO: add one-time construction code here

}

void CBinaryNetwork01Doc::Run()
{	
	int x = cell.getX();
	int y = cell.getY();
	cellStep(world.getValue(x, y), world.getMax());
	world.changeValue(x, y);

}

CBinaryNetwork01Doc::~CBinaryNetwork01Doc()
{
}

void CBinaryNetwork01Doc::cellStep(bool worldValue, int max)
{
	cell.steprun(worldValue, max);
	if (!cell.isAlive()) {
		cell.~Cell();
	}
}

BOOL CBinaryNetwork01Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	
	//cell.generateNode();
	//world.generateRandomWorld();

	return TRUE;
}




// CBinaryNetwork01Doc serialization

void CBinaryNetwork01Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CBinaryNetwork01Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CBinaryNetwork01Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CBinaryNetwork01Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CBinaryNetwork01Doc diagnostics

#ifdef _DEBUG
void CBinaryNetwork01Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBinaryNetwork01Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CBinaryNetwork01Doc commands
