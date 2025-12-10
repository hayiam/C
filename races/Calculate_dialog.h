#pragma once
#include "afxdialogex.h"


// Диалоговое окно Calculate_dialog

class Calculate_dialog : public CDialog
{
	DECLARE_DYNAMIC(Calculate_dialog)

public:
	Calculate_dialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Calculate_dialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnTcnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
};
