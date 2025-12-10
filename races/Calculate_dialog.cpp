// Calculate_dialog.cpp: файл реализации
//

#include "pch.h"
#include "1YB.h"
#include "afxdialogex.h"
#include "Calculate_dialog.h"


// Диалоговое окно Calculate_dialog

IMPLEMENT_DYNAMIC(Calculate_dialog, CDialog)

Calculate_dialog::Calculate_dialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

Calculate_dialog::~Calculate_dialog()
{
}

void Calculate_dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Calculate_dialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &Calculate_dialog::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Calculate_dialog::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// Обработчики сообщений Calculate_dialog


void Calculate_dialog::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void Calculate_dialog::OnTcnSelchangeTab2(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void Calculate_dialog::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}
