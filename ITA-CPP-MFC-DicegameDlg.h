
// ITA-CPP-MFC-DicegameDlg.h: Headerdatei
//

#pragma once


// CITACPPMFCDicegameDlg-Dialogfeld
class CITACPPMFCDicegameDlg : public CDialogEx
{
// Konstruktion
public:
	CITACPPMFCDicegameDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ITACPPMFCDICEGAME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic BMP_Control;
//	CEdit IN_Control;
//	CEdit OUT_Controll;
	CButton B_Controll;
	CBitmap BMP_Loader;
	afx_msg void OnBnClickedRoll();
	int Balance;
	CBitmap V_BitmapLoader;
//	int V_Amount;
	afx_msg void OnEnChangeGuess();
//	int V_Guess;
//	int V_Balance;
//	int V_Balanace;
	int V_Balance;
	int V_Guess;
};
