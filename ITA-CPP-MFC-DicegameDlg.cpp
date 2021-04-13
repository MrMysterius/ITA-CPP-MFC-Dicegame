
// ITA-CPP-MFC-DicegameDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "framework.h"
#include "ITA-CPP-MFC-Dicegame.h"
#include "ITA-CPP-MFC-DicegameDlg.h"
#include "afxdialogex.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CITACPPMFCDicegameDlg-Dialogfeld



CITACPPMFCDicegameDlg::CITACPPMFCDicegameDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ITACPPMFCDICEGAME_DIALOG, pParent)
	, V_Guess(0)
	, V_Balance(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	Balance = 0;
	paused = 0;
}

void CITACPPMFCDicegameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, BMP_IMAGE, BMP_Control);
	//  DDX_Control(pDX, I_Balance, IN_Control);
	//  DDX_Control(pDX, I_Guess, OUT_Controll);
	DDX_Control(pDX, B_Roll, B_Controll);
	//  DDX_Control(pDX, I_Balance, V_Amount);
	//  DDX_Text(pDX, I_Balance, V_Balanace);
	DDX_Text(pDX, I_Balance, V_Balance);
	DDX_Text(pDX, I_Guess, V_Guess);
	DDX_Control(pDX, I_Guess, BTN_Guess);
}

BEGIN_MESSAGE_MAP(CITACPPMFCDicegameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(B_Roll, &CITACPPMFCDicegameDlg::OnBnClickedRoll)
	ON_EN_CHANGE(I_Guess, &CITACPPMFCDicegameDlg::OnEnChangeGuess)
END_MESSAGE_MAP()


// CITACPPMFCDicegameDlg-Meldungshandler

BOOL CITACPPMFCDicegameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen
	Balance = 10;
	BMP_Loader.Detach();
	BMP_Loader.LoadBitmapW(IDB_BITMAP1);
	srand(time(NULL));
	V_Balance = Balance;
	UpdateData(0);
	paused = 1;
	BTN_Guess.SetWindowTextW(NULL);
	BTN_Guess.SetFocus();

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CITACPPMFCDicegameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CITACPPMFCDicegameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CITACPPMFCDicegameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void load(int number, CStatic &Controll, CBitmap &BMP_Loader) {
	Controll.ShowWindow(true);
	BMP_Loader.Detach();
	switch (number)
	{
	case 1:
		BMP_Loader.LoadBitmapW(IDB_BITMAP1);
		break;
	case 2:
		BMP_Loader.LoadBitmapW(IDB_BITMAP2);
		break;
	case 3:
		BMP_Loader.LoadBitmapW(IDB_BITMAP3);
		break;
	case 4:
		BMP_Loader.LoadBitmapW(IDB_BITMAP4);
		break;
	case 5:
		BMP_Loader.LoadBitmapW(IDB_BITMAP5);
		break;
	case 6:
		BMP_Loader.LoadBitmapW(IDB_BITMAP6);
		break;
	}
	Controll.SetBitmap(BMP_Loader);
}

void CITACPPMFCDicegameDlg::OnBnClickedRoll()
{	
	B_Controll.EnableWindow(false);
	UpdateData();
	int rnd = 0;
	int counter = (rand() % 50 + 1) * (rand() % 50 + 1);
	for (int i = 0; i < counter; i++) {
		rnd = rand() % 6 + 1;
		load(rnd, BMP_Control, BMP_Loader);
	}
	if (V_Guess == rnd) {
		Balance += 2;
	}
	else {
		Balance -= 1;
	}
	V_Balance = Balance;
	paused = 1;
	BTN_Guess.SetFocus();
	UpdateData(0);
}


void CITACPPMFCDicegameDlg::OnEnChangeGuess()
{
	if (paused-- >= 1) return;
	UpdateData();
	if (0 < V_Guess && V_Guess < 7 && Balance > 0) {
		B_Controll.EnableWindow(true);
	}
	else {
		B_Controll.EnableWindow(false);
	}
}
