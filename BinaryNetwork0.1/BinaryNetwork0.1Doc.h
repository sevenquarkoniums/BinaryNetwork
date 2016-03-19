
// BinaryNetwork0.1Doc.h : interface of the CBinaryNetwork01Doc class
//


#pragma once
#include "Network.h"

class CBinaryNetwork01Doc : public CDocument
{
protected: // create from serialization only
	CBinaryNetwork01Doc();
	DECLARE_DYNCREATE(CBinaryNetwork01Doc)

// Attributes
public:

// Operations
public:
	void run(int step) {
		network.run(step);
	}
	int getNum() {
		return network.getNum();
	}
	bool getVal(int pos) {
		return network.getVal(pos);
	}
	void steprun() {
		network.steprun();
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
	Network network;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
