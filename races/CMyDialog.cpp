// CMyDialog.cpp: файл реализации
//

#include "pch.h"
#include "1YB.h"
#include "afxdialogex.h"
#include "CMyDialog.h"


// Диалоговое окно CMyDialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений CMyDialog
