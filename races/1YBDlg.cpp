
// 1YBDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "1YB.h"
#include "1YBDlg.h"
#include "afxdialogex.h"
#include "Header.h"
#include "locale"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Диалоговое окно CMy1YBDlg
std::vector<Horse*> horses;
std::vector<Jockey*> jockeys;
std::vector<Pair*> pairs;
std::vector<Race*> races;

Horse* findHorseByName(std::vector<Horse*> horses, CString horse_name) {
    auto found = std::find_if(
        horses.begin(), horses.end(),
        [&](const auto& input) { return input->name == horse_name; });

    if (found == horses.end()) {
        return nullptr;
    }

    return *found;
}

Jockey* findJockeyByName(std::vector<Jockey*> jockeys, CString jockey_name) {
    auto found = std::find_if(
        jockeys.begin(), jockeys.end(),
        [&](const auto& input) { return input->sername == jockey_name; });

    if (found == jockeys.end()) {
        return nullptr;
    }

    return *found;
}

CMy1YBDlg::CMy1YBDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY1YB_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1YBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, tab1);
	DDX_Control(pDX, IDC_STATIC1, horse_name_label);
	DDX_Control(pDX, IDC_EDIT1, horse_name);
	DDX_Control(pDX, IDC_EDIT2, horse_age);
	DDX_Control(pDX, IDC_STATIC2, horse_age_label);
	DDX_Control(pDX, IDC_STATIC3, horse_breed_label);
	DDX_Control(pDX, IDC_EDIT3, horse_breed);
	DDX_Control(pDX, IDC_STATIC4, place_label);
	DDX_Control(pDX, IDC_EDIT4, place);
	DDX_Control(pDX, IDC_STATIC5, owner_label);
	DDX_Control(pDX, IDC_EDIT5, owner);
	DDX_Control(pDX, IDC_STATIC6, jockey_sername_label);
	DDX_Control(pDX, IDC_EDIT6, jokey_sername);
	DDX_Control(pDX, IDC_STATIC7, jokey_first_name_label);
	DDX_Control(pDX, IDC_EDIT7, jockey_first_name);
	DDX_Control(pDX, IDC_STATIC8, jockey_second_name_label);
	DDX_Control(pDX, IDC_EDIT8, jockey_second_name);
	DDX_Control(pDX, IDC_STATIC9, jockey_age_label);
	DDX_Control(pDX, IDC_EDIT9, jockey_age);
	DDX_Control(pDX, IDC_STATIC10, race_name_label);
	DDX_Control(pDX, IDC_EDIT10, race_name);
	DDX_Control(pDX, IDC_STATIC11, race_price_label);
	DDX_Control(pDX, IDC_EDIT11, race_price);
	DDX_Control(pDX, IDC_STATIC12, race_track_label);
	DDX_Control(pDX, IDC_EDIT12, race_track);
	DDX_Control(pDX, IDC_STATIC13, race_day_label);
	DDX_Control(pDX, IDC_STATIC14, race_month_label);
	DDX_Control(pDX, IDC_STATIC15, race_year_label);
	DDX_Control(pDX, IDC_EDIT13, race_day);
	DDX_Control(pDX, IDC_EDIT14, race_month);
	DDX_Control(pDX, IDC_EDIT15, race_year);
	DDX_Control(pDX, IDC_STATIC16, race_horse_name_label);
	DDX_Control(pDX, IDC_STATIC17, race_jockey_name_label);
	DDX_Control(pDX, IDC_BUTTON2, Button2);
	DDX_Control(pDX, IDC_STATIC_Group, Group_of_checks);
	DDX_Control(pDX, IDC_RADIO4, radio1);
	DDX_Control(pDX, IDC_RADIO5, radio2);
	DDX_Control(pDX, IDC_RADIO6, radio3);
	DDX_Control(pDX, IDC_LIST3, list_ctrl);
	DDX_Control(pDX, IDC_BUTTON3, button3);
	DDX_Control(pDX, IDC_BUTTON4, Button1);
	DDX_Control(pDX, IDC_STATIC_place, Insert_place_label);
	DDX_Control(pDX, IDC_EDIT18, Insert_place);
	DDX_Control(pDX, IDC_BUTTON6, Insert_place_button);
	DDX_Control(pDX, IDC_COMBO1, race_horse_name);
	DDX_Control(pDX, IDC_COMBO2, race_jockey_name);
	DDX_Control(pDX, IDC_BUTTON7, add_competitors_button);
}

BEGIN_MESSAGE_MAP(CMy1YBDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMy1YBDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy1YBDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy1YBDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy1YBDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy1YBDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy1YBDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// Обработчики сообщений CMy1YBDlg

BOOL CMy1YBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок
	tab1.InsertItem(0, L"Лошади");
	tab1.InsertItem(1, L"Жокеи");
	tab1.InsertItem(2, L"Гонка");
	tab1.InsertItem(3, L"Расcчитать");

	Button1.ShowWindow(1);
	Button2.ShowWindow(0);
	button3.ShowWindow(0);
	add_competitors_button.ShowWindow(0);

	horse_name_label.ShowWindow(1);
	horse_name.ShowWindow(1);
	horse_age_label.ShowWindow(1);
	horse_age.ShowWindow(1);
	horse_breed_label.ShowWindow(1);
	horse_breed.ShowWindow(1);
	place_label.ShowWindow(1);
	place.ShowWindow(1);
	owner_label.ShowWindow(1);
	owner.ShowWindow(1);

	jockey_sername_label.ShowWindow(0);
	jokey_sername.ShowWindow(0);
	jokey_first_name_label.ShowWindow(0);
	jockey_first_name.ShowWindow(0);
	jockey_second_name_label.ShowWindow(0);
	jockey_second_name.ShowWindow(0);
	jockey_age_label.ShowWindow(0);
	jockey_age.ShowWindow(0);

	race_name_label.ShowWindow(0);
	race_name.ShowWindow(0);
	race_price_label.ShowWindow(0);
	race_price.ShowWindow(0);
	race_track_label.ShowWindow(0);
	race_track.ShowWindow(0);
	race_day_label.ShowWindow(0);
	race_month_label.ShowWindow(0);
	race_year_label.ShowWindow(0);
	race_day.ShowWindow(0);
	race_month.ShowWindow(0);
	race_year.ShowWindow(0);
	race_horse_name_label.ShowWindow(0);
	race_horse_name.ShowWindow(0);
	race_jockey_name_label.ShowWindow(0);
	race_jockey_name.ShowWindow(0);
	Insert_place_label.ShowWindow(0);
	Insert_place.ShowWindow(0);
	Insert_place_button.ShowWindow(0);

	Group_of_checks.ShowWindow(0);
	radio1.ShowWindow(0);
	radio2.ShowWindow(0);
	radio3.ShowWindow(0);
	list_ctrl.ShowWindow(0);
	
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMy1YBDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMy1YBDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy1YBDlg::OnTcnSelchangeTab1(NMHDR* pHMHDR, LRESULT* pResult) {
		int i = tab1.GetCurSel();
	switch(i)
		{
		case 0:
			Button1.ShowWindow(1);
			horse_name_label.ShowWindow(1);
			horse_name.ShowWindow(1);
			horse_age_label.ShowWindow(1);
			horse_age.ShowWindow(1);
			horse_breed_label.ShowWindow(1);
			horse_breed.ShowWindow(1);
			place_label.ShowWindow(1);
			place.ShowWindow(1);
			owner_label.ShowWindow(1);
			owner.ShowWindow(1);

			jockey_sername_label.ShowWindow(0);
			jokey_sername.ShowWindow(0);
			jokey_first_name_label.ShowWindow(0);
			jockey_first_name.ShowWindow(0);
			jockey_second_name_label.ShowWindow(0);
			jockey_second_name.ShowWindow(0);
			jockey_age_label.ShowWindow(0);
			jockey_age.ShowWindow(0);


			race_name_label.ShowWindow(0);
			race_name.ShowWindow(0);
			race_price_label.ShowWindow(0);
			race_price.ShowWindow(0);
			race_track_label.ShowWindow(0);
			race_track.ShowWindow(0);
			race_day_label.ShowWindow(0);
			race_month_label.ShowWindow(0);
			race_year_label.ShowWindow(0);
			race_day.ShowWindow(0);
			race_month.ShowWindow(0);
			race_year.ShowWindow(0);
			race_horse_name_label.ShowWindow(0);
			race_horse_name.ShowWindow(0);
			race_jockey_name_label.ShowWindow(0);
			race_jockey_name.ShowWindow(0);
			Insert_place_label.ShowWindow(0);
			Insert_place.ShowWindow(0);
			Insert_place_button.ShowWindow(0);


			Group_of_checks.ShowWindow(0);
			radio1.ShowWindow(0);
			radio2.ShowWindow(0);
			radio3.ShowWindow(0);
			list_ctrl.ShowWindow(0);
			Button2.ShowWindow(0);
			button3.ShowWindow(0);
			add_competitors_button.ShowWindow(0);
			break;
		case 1:
			Button1.ShowWindow(1);
			horse_name_label.ShowWindow(0);
			horse_name.ShowWindow(0);
			horse_age_label.ShowWindow(0);
			horse_age.ShowWindow(0);
			horse_breed_label.ShowWindow(0);
			horse_breed.ShowWindow(0);
			place_label.ShowWindow(0);
			place.ShowWindow(0);
			owner_label.ShowWindow(0);
			owner.ShowWindow(0);

			jockey_sername_label.ShowWindow(1);
			jokey_sername.ShowWindow(1);
			jokey_first_name_label.ShowWindow(1);
			jockey_first_name.ShowWindow(1);
			jockey_second_name_label.ShowWindow(1);
			jockey_second_name.ShowWindow(1);
			jockey_age_label.ShowWindow(1);
			jockey_age.ShowWindow(1);

			race_name_label.ShowWindow(0);
			race_name.ShowWindow(0);
			race_price_label.ShowWindow(0);
			race_price.ShowWindow(0);
			race_track_label.ShowWindow(0);
			race_track.ShowWindow(0);
			race_day_label.ShowWindow(0);
			race_month_label.ShowWindow(0);
			race_year_label.ShowWindow(0);
			race_day.ShowWindow(0);
			race_month.ShowWindow(0);
			race_year.ShowWindow(0);
			race_horse_name_label.ShowWindow(0);
			race_horse_name.ShowWindow(0);
			race_jockey_name_label.ShowWindow(0);
			race_jockey_name.ShowWindow(0);
			Insert_place_label.ShowWindow(0);
			Insert_place.ShowWindow(0);
			Insert_place_button.ShowWindow(0);

			Group_of_checks.ShowWindow(0);
			radio1.ShowWindow(0);
			radio2.ShowWindow(0);
			radio3.ShowWindow(0);
			list_ctrl.ShowWindow(0);
			Button2.ShowWindow(0);
			button3.ShowWindow(0);
			add_competitors_button.ShowWindow(0);
			break;
		case 2:
			for (const auto& vec : horses) {
				race_horse_name.AddString(vec->name);
			};
			for (const auto& vec : jockeys)
				race_jockey_name.AddString(vec->sername);
			Button1.ShowWindow(1);
			horse_name_label.ShowWindow(0);
			horse_name.ShowWindow(0);
			horse_age_label.ShowWindow(0);
			horse_age.ShowWindow(0);
			horse_breed_label.ShowWindow(0);
			horse_breed.ShowWindow(0);
			place_label.ShowWindow(0);
			place.ShowWindow(0);
			owner_label.ShowWindow(0);
			owner.ShowWindow(0);

			jockey_sername_label.ShowWindow(0);
			jokey_sername.ShowWindow(0);
			jokey_first_name_label.ShowWindow(0);
			jockey_first_name.ShowWindow(0);
			jockey_second_name_label.ShowWindow(0);
			jockey_second_name.ShowWindow(0);
			jockey_age_label.ShowWindow(0);
			jockey_age.ShowWindow(0);

			race_name_label.ShowWindow(1);
			race_name.ShowWindow(1);
			race_price_label.ShowWindow(1);
			race_price.ShowWindow(1);
			race_track_label.ShowWindow(1);
			race_track.ShowWindow(1);
			race_day_label.ShowWindow(1);
			race_month_label.ShowWindow(1);
			race_year_label.ShowWindow(1);
			race_day.ShowWindow(1);
			race_month.ShowWindow(1);
			race_year.ShowWindow(1);
			race_horse_name_label.ShowWindow(1);
			race_horse_name.ShowWindow(1);
			race_jockey_name_label.ShowWindow(1);
			race_jockey_name.ShowWindow(1);
			Insert_place_label.ShowWindow(1);
			Insert_place.ShowWindow(1);
			Insert_place_button.ShowWindow(1);

			Group_of_checks.ShowWindow(0);
			radio1.ShowWindow(0);
			radio2.ShowWindow(0);
			radio3.ShowWindow(0);
			list_ctrl.ShowWindow(0);
			Button2.ShowWindow(0);
			button3.ShowWindow(0);
			add_competitors_button.ShowWindow(1);
			break;

		case 3:
			Button1.ShowWindow(0);
			horse_name_label.ShowWindow(0);
			horse_name.ShowWindow(0);
			horse_age_label.ShowWindow(0);
			horse_age.ShowWindow(0);
			horse_breed_label.ShowWindow(0);
			horse_breed.ShowWindow(0);
			place_label.ShowWindow(0);
			place.ShowWindow(0);
			owner_label.ShowWindow(0);
			owner.ShowWindow(0);

			jockey_sername_label.ShowWindow(0);
			jokey_sername.ShowWindow(0);
			jokey_first_name_label.ShowWindow(0);
			jockey_first_name.ShowWindow(0);
			jockey_second_name_label.ShowWindow(0);
			jockey_second_name.ShowWindow(0);
			jockey_age_label.ShowWindow(0);
			jockey_age.ShowWindow(0);

			race_name_label.ShowWindow(0);
			race_name.ShowWindow(0);
			race_price_label.ShowWindow(0);
			race_price.ShowWindow(0);
			race_track_label.ShowWindow(0);
			race_track.ShowWindow(0);
			race_day_label.ShowWindow(0);
			race_month_label.ShowWindow(0);
			race_year_label.ShowWindow(0);
			race_day.ShowWindow(0);
			race_month.ShowWindow(0);
			race_year.ShowWindow(0);
			race_horse_name_label.ShowWindow(0);
			race_horse_name.ShowWindow(0);
			race_jockey_name_label.ShowWindow(0);
			race_jockey_name.ShowWindow(0);
			Insert_place_label.ShowWindow(0);
			Insert_place.ShowWindow(0);
			Insert_place_button.ShowWindow(0);

			Group_of_checks.ShowWindow(1);
			radio1.ShowWindow(1);
			radio2.ShowWindow(1);
			radio3.ShowWindow(1);
			list_ctrl.ShowWindow(1);
			Button2.ShowWindow(1);
			button3.ShowWindow(1);
			add_competitors_button.ShowWindow(0);
			break;
		}
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}

void CMy1YBDlg::OnBnClickedButton2()
{
	if (radio1.GetCheck() == BST_CHECKED) {
		Horse m_winner = most_winner_horse(races);
		Horse* most_winner = findHorseByName(horses, m_winner.name);
		CRect rect;
		CString str;
		str.Format(L"%d", most_winner->age);
		CListCtrl* myList = (CListCtrl*)GetDlgItem(IDC_LIST3);
		myList->DeleteColumn(0);
		myList->DeleteColumn(1);
		myList->DeleteAllItems();
		myList->GetClientRect(rect);
		myList->InsertColumn(0, L"Имя", 0, rect.Width() / 5);
		myList->InsertColumn(1, L"Место", 0, (rect.Width() / 5));
		myList->InsertColumn(1, L"Возраст", 0, (rect.Width() / 5));
		myList->InsertColumn(1, L"Владелец", 0, (rect.Width() / 5));
		myList->InsertColumn(1, L"Порода", 0, (rect.Width() / 5));
		myList->InsertItem(0, L"", 0); // 0 is the index of the item
		myList->SetItemText(0, 0, most_winner->name);
		myList->SetItemText(0, 1, most_winner->breed);
		myList->SetItemText(0, 2, most_winner->owner);
		myList->SetItemText(0, 3, str);
		myList->SetItemText(0, 4, most_winner->place);
	}
	if (radio2.GetCheck() == BST_CHECKED) {
		CString m_track = most_freq_track(races);
		CRect rect;
		CListCtrl* myList = (CListCtrl*)GetDlgItem(IDC_LIST3);
		myList->DeleteColumn(0);
		myList->DeleteColumn(1);
		myList->DeleteAllItems();
		myList->GetClientRect(rect);
		myList->InsertColumn(0, L"Название трэка", 0, rect.Width());
		myList->InsertItem(0, m_track, 0); // 0 is the index of the item
		myList->SetItemText(0, 1, m_track);
	}
	if (radio3.GetCheck() == BST_CHECKED) {
		Jockey m_winner_jockey = most_winner_jockey(races);
		Jockey* most_winner = findJockeyByName(jockeys, m_winner_jockey.sername);
		CListCtrl* myList = (CListCtrl*)GetDlgItem(IDC_LIST3);
		CRect rect;
		CString str;
		str.Format(L"%d", most_winner->age);
		myList->DeleteColumn(0);
		myList->DeleteColumn(1);
		myList->DeleteAllItems();
		myList->GetClientRect(rect);
		myList->InsertColumn(0, L"Имя", 0, rect.Width() / 4);
		myList->InsertColumn(1, L"Возраст", 0, (rect.Width() / 4));
		myList->InsertColumn(1, L"Отчество", 0, (rect.Width() / 4));
		myList->InsertColumn(1, L"Фамилия", 0, (rect.Width() / 4));
		myList->InsertItem(0, most_winner->first_name, 0); // 0 is the index of the item
		myList->SetItemText(0, 0, most_winner->first_name);
		myList->SetItemText(0, 1, most_winner->sername);
		myList->SetItemText(0, 2, most_winner->second_name);
		myList->SetItemText(0, 3, str);
	}
}

void CMy1YBDlg::OnBnClickedButton3()
{ /*
    // Create a file dialog
    CFileDialog fileDialog(FALSE, L"txt", L"output.txt", OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, L"Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");

    // Check if the file dialog was successfully created
    if (fileDialog.DoModal() == IDOK)
    {
        // Get the path of the selected file
       CString filePath = fileDialog.GetPathName();

        // Open the file for writing
       CFile file;
	   if (file.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
			{
				if(radio1.GetCheck() == BST_CHECKED) {
					UpdateData(TRUE);
					Horse m_winner = most_winner_horse(races);
					Horse* most_winner = findHorseByName(horses, m_winner.name);
					CString str;
					str.Format(L"%d", most_winner->age);
					CString rowData = most_winner->name + " " + most_winner->breed + " " +  most_winner->owner + " " +  str + " " +  most_winner->place;
					file.Write(rowData.GetBuffer(), rowData.GetLength());
				}
				if (radio2.GetCheck() == BST_CHECKED) {
					UpdateData(TRUE);
					CString m_track = most_freq_track(races);
					file.Write(m_track.GetBuffer(), m_track.GetLength());
				}
				if (radio3.GetCheck() == BST_CHECKED) {
					Jockey m_winner_jockey = most_winner_jockey(races);
					Jockey* most_winner = findJockeyByName(jockeys, m_winner_jockey.sername);
					CString str;
					str.Format(L"%d", most_winner->age);
					CString rowData = most_winner->first_name + " " + most_winner->sername + " " + most_winner->second_name + " " + str;
					file.Write(rowData.GetBuffer(), rowData.GetLength());
				}
					file.Close();
			}
			else
			{
				// Handle the error
				AfxMessageBox(L"Ошибка при записи файла");
			}
		}
		else
		{
			// Handle the cancel
			AfxMessageBox(L"Запись файла была преравана");
		}*/
	// Create a file dialog
 // Create a file dialog
    CFileDialog fileDialog(FALSE, L"txt", L"output.txt", OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, L"Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");

    // Check if the file dialog was successfully created
    if (fileDialog.DoModal() == IDOK)
    {
        // Get the path of the selected file
        CString filePath = fileDialog.GetPathName();

        // Open the file for writing

        CFile file;
        if (file.Open(filePath, CFile::modeCreate | CFile::modeWrite))
        {
            // Get the list control

			CListCtrl* listCtrl = (CListCtrl*)GetDlgItem(IDC_LIST3);
            // Get the number of rows and columns
            int numRows = listCtrl->GetItemCount();
            int numCols = listCtrl->GetHeaderCtrl()->GetItemCount();

            // Write the data to the file
            for (int i = 0; i < numRows; i++)
            {
                CString rowData;
                for (int j = 0; j < numCols; j++)
                {
                    CString cellData = listCtrl->GetItemText(i, j);
                    rowData += cellData;
                    if (j < numCols - 1)
                        rowData += _T(","); // Separate columns with a comma
                }
                rowData += _T("\r\n"); // Separate rows with a newline
				int t_length = rowData.GetLength() + 1;
				file.Write(rowData.GetBufferSetLength(rowData.GetLength()), t_length*2); // + 1 *2 ?
            }

            file.Close();
        }
        else
        {
            // Handle the error
            AfxMessageBox(L"Не удалось открыть файл для записи");
        }
    }
    else
    {
        // Handle the cancel
        AfxMessageBox(L"Сохранение файла было отменено");
    }
}

// кнопка "Добавить"
void CMy1YBDlg::OnBnClickedButton4()
{
	if (tab1.GetCurSel() == 0) {
		CString name, age, breed, hplace, howner;
		horse_name.GetWindowText(name);
		horse_age.GetWindowText(age);
		horse_breed.GetWindowText(breed);
		place.GetWindowText(hplace);
		owner.GetWindowText(howner);
		if (name == L"")
			AfxMessageBox(L"Не введено имя");
		else if (age == L"")
			AfxMessageBox(L"Не введен возраст");
		else if (age.SpanIncluding(_T("0123456789")) != age)
			AfxMessageBox(L"Неверный формат возраста");
		else if (breed == L"")
			AfxMessageBox(L"Не введена порода");
		else if (hplace == L"")
			AfxMessageBox(L"Не введено место");
		else if (howner == L"")
			AfxMessageBox(L"Не введен владелец");
		/*int num = _wtoi(name);
		CString var;
		int num = 34;
		var.Format(L"%d", num);*/
		else {
			horses.push_back(new Horse(name, breed, _wtoi(age), howner, hplace));
			AfxMessageBox(L"Данные добавлены!");
		}
	}

	if (tab1.GetCurSel() == 1) {
		CString sername, name, second_name, age;
		jokey_sername.GetWindowText(sername);
		jockey_second_name.GetWindowText(second_name);
		jockey_first_name.GetWindowText(name);
		jockey_age.GetWindowText(age);
		if (name == L"")
			AfxMessageBox(L"Не введено название");
		else if (age == L"")
			AfxMessageBox(L"Не введен возраст");
		else if (second_name == L"")
			AfxMessageBox(L"Не введена отчество");
		else if (age == L"")
			AfxMessageBox(L"Не введен возраст");
		else if (age.SpanIncluding(_T("0123456789")) != age)
			AfxMessageBox(L"Неверный формат возраста");
		/*int num = _wtoi(name);
		CString var;
		int num = 34;
		var.Format(L"%d", num);*/
		else {
			jockeys.push_back(new Jockey(sername, name, second_name, _wtoi(age)));
			AfxMessageBox(L"Данные добавлены");
		}
	}

	if (tab1.GetCurSel() == 2) {
		CString name, price, track, day, month, year, horse_name, jockey_name, place;
		race_name.GetWindowText(name);
		race_price.GetWindowText(price);
		race_track.GetWindowText(track);
		race_day.GetWindowText(day);
		race_month.GetWindowText(month);
		race_year.GetWindowText(year);
		race_horse_name.GetWindowText(horse_name);
		race_jockey_name.GetWindowText(jockey_name);
		if (name == L"")
			AfxMessageBox(L"Не введено название");
		else if (price == L"")
			AfxMessageBox(L"Не введен размер приза");
		else if (price.SpanIncluding(_T("0123456789")) != price)
			AfxMessageBox(L"Неверный формат награды");
		else if (track == L"")
			AfxMessageBox(L"Не введен ипподром");
		else if (day == L"")
			AfxMessageBox(L"Не введен день");
		else if (day.SpanIncluding(_T("0123456789")) != day)
			AfxMessageBox(L"Неверный формат дня (формат должен быть вида '01')");
		else if (month == L"")
			AfxMessageBox(L"Не введен месяц");
		else if (month.SpanIncluding(_T("0123456789")) != month)
			AfxMessageBox(L"Неверный формат месяца (формат должен быть вида '11')");
		else if (year == L"")
			AfxMessageBox(L"Не введен год");
		else if (year.SpanIncluding(_T("0123456789")) != year)
			AfxMessageBox(L"Неверный формат года (формат должен быть вида '2015')");
		else if (horse_name == L"")
			AfxMessageBox(L"Не введено имя лошади");
		else if (jockey_name == L"")
			AfxMessageBox(L"Не введено имя жокея");
		/*int num = _wtoi(name);
		CString var;
		int num = 34;
		var.Format(L"%d", num);*/
		else {
			for (auto& vec : jockeys) {
				for (auto& vc : horses) {
					pairs.push_back(new Pair(*vc, *vec));
				}
			}
			races.push_back(new Race(name, _wtoi(price), track, _wtoi(day), _wtoi(month), _wtoi(year)));
			races.back()->addCompetitors(pairs.back()->horse, pairs.back()->jockey);
			AfxMessageBox(L"Данные добавлены!");
		}
	}
}


void CMy1YBDlg::OnBnClickedButton6()
{
	CString horse_name;
	race_horse_name.GetWindowText(horse_name);
	CString jockey_name;
	race_jockey_name.GetWindowText(jockey_name);
	CString position;
	Insert_place.GetWindowText(position);
	Horse* found_horse = findHorseByName(horses, horse_name);
	Jockey* found_jockey = findJockeyByName(jockeys, jockey_name);
	Pair pair(*found_horse, *found_jockey);
	if (!races.empty()) {
	races.back()->replace_to_position(pair, _wtoi(position));
	AfxMessageBox(L"Позиция изменена на " + position);
	}
}



void CMy1YBDlg::OnBnClickedButton7()
{
	CString horse_name, jockey_name;
	race_horse_name.GetWindowText(horse_name);
	race_jockey_name.GetWindowText(jockey_name);
	Horse* found_horse = findHorseByName(horses, horse_name);
	Jockey* found_jockey = findJockeyByName(jockeys, jockey_name);
	Pair pair(*found_horse, *found_jockey);

	if (!races.empty()) {
		races.back()->addCompetitors(*found_horse, *found_jockey);
		AfxMessageBox(L"Данные добавлены");
	}
}
