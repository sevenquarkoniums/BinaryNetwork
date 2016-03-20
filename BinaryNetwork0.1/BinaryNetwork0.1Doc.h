
// BinaryNetwork0.1Doc.h : interface of the CBinaryNetwork01Doc class
//


#pragma once
#include "Cell.h"
#include "World.h"

class CBinaryNetwork01Doc : public CDocument
{
protected: // create from serialization only
	CBinaryNetwork01Doc();
	DECLARE_DYNCREATE(CBinaryNetwork01Doc)

// Attributes
public:

// Operations
public:
	void Run();
	int getCellNum() {
		return cell.getNum();
	}
	bool getCellVal(int pos) {
		return cell.getVal(pos);
	}
	int cellX() {
		return cell.getX();
	}
	int cellY() {
		return cell.getY();
	}
	int getCellSize() {
		return cell.cellSize;
	}
	void cellStep(bool worldValue, int max);

	bool getWorldVal(int x, int y)
	{
		return world.getValue(x, y);
	}
	int getWorldMax() {
		return world.getMax();
	}
	int getWorldLength() {
		return world.getLength();
	}
	//int getStep() {
	//	return network.getStep();
	//}

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
	World world;
	Cell cell;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
