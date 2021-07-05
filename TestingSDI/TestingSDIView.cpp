
// TestingSDIView.cpp : implementation of the CTestingSDIView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestingSDI.h"
#endif

#include "TestingSDIDoc.h"
#include "TestingSDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestingSDIView

IMPLEMENT_DYNCREATE(CTestingSDIView, CView)

BEGIN_MESSAGE_MAP(CTestingSDIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestingSDIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTestingSDIView construction/destruction

CTestingSDIView::CTestingSDIView() noexcept
{
	// TODO: add construction code here

}

CTestingSDIView::~CTestingSDIView()
{
}

BOOL CTestingSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestingSDIView drawing

void CTestingSDIView::OnDraw(CDC* pDC)
{
	CTestingSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(600, 100, _T("Hello Teja Anuchuri"));

	// TODO: add draw code for native data here
}


// CTestingSDIView printing


void CTestingSDIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestingSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestingSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestingSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestingSDIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestingSDIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestingSDIView diagnostics

#ifdef _DEBUG
void CTestingSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CTestingSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestingSDIDoc* CTestingSDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestingSDIDoc)));
	return (CTestingSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestingSDIView message handlers
