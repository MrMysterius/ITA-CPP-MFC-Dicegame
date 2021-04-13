
// ITA-CPP-MFC-Dicegame.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CITACPPMFCDicegameApp:
// Siehe ITA-CPP-MFC-Dicegame.cpp für die Implementierung dieser Klasse
//

class CITACPPMFCDicegameApp : public CWinApp
{
public:
	CITACPPMFCDicegameApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CITACPPMFCDicegameApp theApp;
