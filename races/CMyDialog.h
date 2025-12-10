#pragma once
#include "afxdialogex.h"


// Диалоговое окно CMyDialog

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CMyDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
