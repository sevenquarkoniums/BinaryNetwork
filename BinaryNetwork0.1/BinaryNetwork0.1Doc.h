
// BinaryNetwork0.1Doc.h : interface of the CBinaryNetwork01Doc class
//


#pragma once
#include "Cell.h"
#include "World.h"
#include <list>

class CBinaryNetwork01Doc : public CDocument
{
protected: // create from serialization only
	//set random seed. Generate World and all the labs.
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

	//In one labDay, let all Cells in all Worlds move one step.
	void runAll();
	//Run all Cells one step. If died, create a new one.
	void stableRun();
	//Create new Cells according to mutability.
	void reproduce();
	int reproDay;
	int getLabDay();
	int getBest();

	World* getSampleWorld();
	//we cannot use list<Cell> here. push_back a Cell into list<Cell> results in change.
	std::list<Cell*>::iterator getCellHead();
	std::list<Cell*>::iterator getCellEnd();

// Overrides
public:
	//currently nothing happens.
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	//delete all the Worlds and Cells.
	virtual ~CBinaryNetwork01Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//Number of different simulation running simultaneously. non-static initialization not supported in .h
	int labNum;
	double mutability;
	int reproNum;
	int labDay;
	//records the farthest place reached by cell.
	int best;

	Cell* newCell;
	World* newWorld;
	std::list<Cell*> tube;
	std::list<World*> medium;
	//Used in GUI, because empty worlds are all the same for all labs.
	World* sampleWorld;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
