
// 1YBDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMy1YBDlg
class CMy1YBDlg : public CDialogEx
{
// Создание
public:
	CMy1YBDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY1YB_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	CTabCtrl tab1;
	CButton Button1;
	afx_msg void OnBnClickedButton1();
	CButton Button2;
	afx_msg void OnEnChangeEdit1();
	CEdit Horse_name;
	afx_msg void OnEnChangeEdit3();
	CStatic horse_name_label;
	CEdit horse_name;
	CStatic Age_title;
	CStatic horse_age_title;
	CEdit horse_age;
	CStatic horse_age_label;
	CStatic horse_bree_label;
	CEdit horese_breed;
	CStatic place_label;
	CEdit place;
	CStatic owner_label;
	CEdit owner;
	CStatic horse_breed_label;
	CEdit horse_breed;
	afx_msg void OnStnClickedStatic1();
	CStatic jockey_sername_label;
	CEdit jokey_sername;
	CStatic jokey_first_name_label;
	CEdit jockey_first_name;
	CStatic second_name_label;
	CStatic jockey_second_name_label;
	CEdit jockey_second_name;
	CStatic jockey_age_label;
	CEdit jockey_age;
	afx_msg void OnStnClickedStatic10();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	CStatic race_name_label;
	CEdit race_name;
	CStatic race_price_label;
	CEdit race_price;
	CStatic race_track_label;
	CEdit race_track;
	CStatic race_day_label;
	CStatic race_month_label;
	CStatic race_year_label;
	CEdit race_day;
	CEdit race_month;
	CEdit race_year;
	CStatic race_horse_name_label;
	CStatic race_jockey_name_label;
	afx_msg void OnBnClickedButton2();
	CStatic Group_of_checks;
	CButton radio1;
	CButton radio2;
	CButton radio3;
	CListCtrl list_ctrl;
	afx_msg void OnBnClickedButton3();
	CButton button3;
	CButton button1;
	afx_msg void OnBnClickedButton4();
	CStatic Insert_place_label;
	CEdit Insert_place;
	CButton Insert_place_button;
	CComboBox race_horse_name;
	CComboBox race_jockey_name;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	CButton add_competitors_button;
};
