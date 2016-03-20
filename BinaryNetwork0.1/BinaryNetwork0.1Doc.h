
// BinaryNetwork0.1Doc.h : interface of the CBinaryNetwork01Doc class
//


#pragma once
#include "Cell.h"
#include "World.h"
#include <list>

class CBinaryNetwork01Doc : public CDocument
{
protected: // create from serialization only
	CBinaryNetwork01Doc();
	DECLARE_DYNCREATE(CBinaryNetwork01Doc)

// Attributes
public:

// Operations
public:
	int getCellNum(std::list<Cell*>::iterator iCell);
	bool getCellVal(std::list<Cell*>::iterator iCell, int pos);
	int cellX(std::list<Cell*>::iterator iCell);
	int cellY(std::list<Cell*>::iterator iCell);

	bool getWorldVal(std::list<World*>::iterator iWorld, int x, int y);
	bool getWorldVal(World* sample, int x, int y);
	int getWorldMax(std::list<World*>::iterator iWorld);
	int getWorldMax(World* sample);
	int getWorldLength(std::list<World*>::iterator iWorld);

	void setInitLabNum(int num);
	int getLabNum();
	void setMutability(double num);
	void runAll();
	void runToEnd();

	World* getSampleWorld();
	//we cannot use list<Cell> here. push_back a Cell into list<Cell> results in change.
	std::list<Cell*>::iterator getCellHead();
	std::list<Cell*>::iterator getCellEnd();

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CBinaryNetwork01Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int labNum;//non-static initialization not supported in .h
	double mutability;
	Cell* newCell;
	World* newWorld;
	std::list<Cell*> tube;
	std::list<World*> medium;
	World* sampleWorld;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
