
// 1YB.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMy1YBApp:
// Сведения о реализации этого класса: 1YB.cpp
//

class CMy1YBApp : public CWinApp
{
public:
	CMy1YBApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMy1YBApp theApp;
