
// BinaryNetwork0.1Doc.cpp : implementation of the CBinaryNetwork01Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "BinaryNetwork0.1.h"
#endif

#include "BinaryNetwork0.1Doc.h"
//#include <list>
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
	:labNum(300), mutability(0.1), reproNum(32), reproDay(10), labDay(0), best(0), sampleWorld(NULL)
{
	srand(time(NULL));//srand no more than once!!
	sampleWorld = new World;
	for (int i = 0; i < labNum; i++) {
		tube.push_back(new Cell);
		medium.push_back(new World);
	}
}

int CBinaryNetwork01Doc::getCellNum(std::list<Cell*>::iterator iCell)
{
	return (*iCell)->getNum();
}

bool CBinaryNetwork01Doc::getCellVal(std::list<Cell*>::iterator iCell, int pos)
{
	return (*iCell)->getVal(pos);
}

int CBinaryNetwork01Doc::cellX(std::list<Cell*>::iterator iCell)
{
	return (*iCell)->getX();
}

int CBinaryNetwork01Doc::cellY(std::list<Cell*>::iterator iCell)
{
	return (*iCell)->getY();
}

bool CBinaryNetwork01Doc::getWorldVal(std::list<World*>::iterator iWorld, int x, int y)
{
	return (*iWorld)->getValue(x, y);
}

bool CBinaryNetwork01Doc::getWorldVal(World * sample, int x, int y)
{
	return sample->getValue(x, y);
}

int CBinaryNetwork01Doc::getWorldMax(std::list<World*>::iterator iWorld)
{
	return (*iWorld)->getMax();
}

int CBinaryNetwork01Doc::getWorldMax(World * sample)
{
	return sample->getMax();
}

int CBinaryNetwork01Doc::getWorldLength(std::list<World*>::iterator iWorld)
{
	return (*iWorld)->getLength();
}

void CBinaryNetwork01Doc::setInitLabNum(int num)
{
	labNum = num;
}

int CBinaryNetwork01Doc::getLabNum()
{
	return labNum;
}

void CBinaryNetwork01Doc::setMutability(double num)
{
	mutability = num;
}

CBinaryNetwork01Doc::~CBinaryNetwork01Doc()
{
	sampleWorld->~World();
	std::list<Cell*>::iterator iCell = tube.begin();
	std::list<World*>::iterator iWorld = medium.begin();
	while (iCell != tube.end()) {
		(*iCell)->~Cell();
		(*iWorld)->~World();
		iCell = tube.erase(iCell);
		iWorld = medium.erase(iWorld);
	}
}

void CBinaryNetwork01Doc::runAll()
{
	std::list<Cell*>::iterator iCell = tube.begin();
	std::list<World*>::iterator iWorld = medium.begin();
	while(iCell != tube.end()) {
		int x = (*iCell)->getX();
		int y = (*iCell)->getY();
		if (x > best) {
			best = x;
		}

		(*iCell)->steprun((*iWorld)->getValue(x, y), (*iWorld)->getMax());
		(*iWorld)->updateValue(x, y);

		if (!(*iCell)->isAlive()) {
			(*iCell)->~Cell();
			(*iWorld)->~World();
			iCell = tube.erase(iCell);
			iWorld = medium.erase(iWorld);
			labNum--;
		}
		else {
			++iCell;
			++iWorld;
		}
	}
	labDay++;
}

void CBinaryNetwork01Doc::stableRun()
{
	std::list<Cell*>::iterator iCell = tube.begin();
	std::list<World*>::iterator iWorld = medium.begin();
	while (iCell != tube.end()) {
		int x = (*iCell)->getX();
		int y = (*iCell)->getY();
		if (x > best) {
			best = x;
		}

		(*iCell)->steprun((*iWorld)->getValue(x, y), (*iWorld)->getMax());
		(*iWorld)->updateValue(x, y);

		if (!(*iCell)->isAlive()) {
			(*iCell)->~Cell();
			(*iWorld)->~World();
			iCell = tube.erase(iCell);
			iWorld = medium.erase(iWorld);
			tube.push_front(new Cell);
			medium.push_front(new World);
			labNum++;
		}
		else {
			++iCell;
			++iWorld;
		}
	}
	labDay++;
}

void CBinaryNetwork01Doc::reproduce()
{
	std::list<Cell*>::iterator iCell = tube.begin();
	std::list<World*>::iterator iWorld = medium.begin();
	while (iCell != tube.end()) {
		for (int i = 0; i < reproNum; i++) {
			tube.push_front(new Cell(**iCell, mutability));
			medium.push_front(new World);
		}
		//tube.push_front(new Cell(**iCell));
		//medium.push_front(new World);
		labNum += reproNum;
		++iCell;
		++iWorld;
	}
}

int CBinaryNetwork01Doc::getLabDay()
{
	return labDay;
}

int CBinaryNetwork01Doc::getBest()
{
	return best;
}

World * CBinaryNetwork01Doc::getSampleWorld()
{
	return sampleWorld;
}

std::list<Cell*>::iterator CBinaryNetwork01Doc::getCellHead()
{
	return tube.begin();
}

std::list<Cell*>::iterator CBinaryNetwork01Doc::getCellEnd()
{
	return tube.end();
}

BOOL CBinaryNetwork01Doc::OnNewDocument()//this function is not called at first run.
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	//just destructor and constructor again.
	//sampleWorld->~World();
	//std::list<Cell*>::iterator iCell = tube.begin();
	//std::list<World*>::iterator iWorld = medium.begin();
	//while (iCell != tube.end()) {
	//	(*iCell)->~Cell();
	//	(*iWorld)->~World();
	//	iCell = tube.erase(iCell);
	//	iWorld = medium.erase(iWorld);
	//}

	//labNum = 1000;
	//mutability = 0.1;
	//reproNum = 256;
	//reproDay = 7;
	//labDay = 0;
	//best = 0;
	//sampleWorld = new World;
	//for (int i = 0; i < labNum; i++) {
	//	tube.push_back(new Cell);
	//	medium.push_back(new World);
	//}

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
