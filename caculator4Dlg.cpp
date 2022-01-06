
// caculator4Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "caculator4.h"
#include "caculator4Dlg.h"
#include "afxdialogex.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// Ccaculator4Dlg 대화 상자



Ccaculator4Dlg::Ccaculator4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CACULATOR4_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ccaculator4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ccaculator4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_plu, &Ccaculator4Dlg::OnBnClickedButtonplu)
	ON_BN_CLICKED(IDC_BUTTON_minu, &Ccaculator4Dlg::OnBnClickedButtonminu)
	ON_BN_CLICKED(IDC_BUTTON_mult, &Ccaculator4Dlg::OnBnClickedButtonmult)
	ON_BN_CLICKED(IDC_BUTTON_div, &Ccaculator4Dlg::OnBnClickedButtondiv)
	ON_BN_CLICKED(IDC_BUTTON_eql, &Ccaculator4Dlg::OnBnClickedButtoneql)
	ON_BN_CLICKED(IDC_BUTTON_clear, &Ccaculator4Dlg::OnBnClickedButtonclear)
	ON_BN_CLICKED(IDC_BUTTON_dot, &Ccaculator4Dlg::OnBnClickedButtondot)
	ON_BN_CLICKED(IDC_BUTTON_backspace, &Ccaculator4Dlg::OnBnClickedButtonbackspace)
	ON_BN_CLICKED(IDC_BUTTON_root, &Ccaculator4Dlg::OnBnClickedButtonroot)
	ON_BN_CLICKED(IDC_BUTTON_zeagop, &Ccaculator4Dlg::OnBnClickedButtonzeagop)
	ON_BN_CLICKED(IDC_BUTTON_boonsoo, &Ccaculator4Dlg::OnBnClickedButtonboonsoo)
	ON_BN_CLICKED(IDC_BUTTON_allclear, &Ccaculator4Dlg::OnBnClickedButtonallclear)
	ON_BN_CLICKED(IDC_BUTTON_plma, &Ccaculator4Dlg::OnBnClickedButtonplma)
	ON_BN_CLICKED(IDC_BUTTON_persent, &Ccaculator4Dlg::OnBnClickedButtonpersent)
END_MESSAGE_MAP()


// Ccaculator4Dlg 메시지 처리기

BOOL Ccaculator4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	//제목코드
	CString str;
	str.Format(L" 20174147 강경민 -계산기-");
	SetWindowText(str);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Ccaculator4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Ccaculator4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Ccaculator4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL Ccaculator4Dlg::OnCommand(WPARAM wParam, LPARAM lParam)   //매크로 ID값을 이용하기 위한 함수
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (IDC_BUTTON_0 <= wParam && wParam <= IDC_BUTTON_9) {    //솔루션 탐색기-> Resource.h -> 숫자버튼 매크로 확인
		CString str, number_str, str2;
		number_str.Format(L"%d", wParam - IDC_BUTTON_0);       //숫자 '0'을 기준으로 잠음.

		if (step == 0) {                //연산자가 눌리지 않았을 경우
			GetDlgItemText(IDC_EDIT1, str2); //에디트에 입력된 값을 변수에 저장
		}
		else if (step == 1) {          //연산자가 눌렸을 경우
			GetDlgItemText(IDC_EDIT1, str);
			step = 0;
			value = _wtof(str);
		}
		SetDlgItemText(IDC_EDIT1, str2 + number_str); //str에 저장된 값에 숫자값을 더해 출력
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

void Ccaculator4Dlg::M_operate(double value2)    //사칙연산 추가한 함수
{
	switch (flag) {
	case 0:  //더하기
		value += value2;
		break;
	case 1:  //빼기
		value -= value2;
		break;
	case 2:  //곱하기
		value *= value2;
		break;
	case 3:  //나누기
		if (value2 != 0) {
			value /= value2;
		}
		else {
			AfxMessageBox(L"0으로 나눌 수 없습니다.");  //에러 메세지 출력
			value = 0;
		}
		break;
	}
}
void Ccaculator4Dlg::OnBnClickedButtonplu()    //더하기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;
	double value2;
	GetDlgItemText(IDC_EDIT1, omg);
	value2 = _wtof(omg);

	count++;
	if (count == 1) {
		value = value2;
	}
	else {
		M_operate(value2);
	}

	flag = 0;
	step = 1;

	GetDlgItemText(IDC_EDIT1, str2);
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + str2 + L"+");

	omg.Format(L"%f", value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(IDC_EDIT1, omg);
}


void Ccaculator4Dlg::OnBnClickedButtonminu()   //빼기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;
	double value2;
	GetDlgItemText(IDC_EDIT1, omg);
	value2 = _wtof(omg);

	count++;
	if (count == 1) {
		value = value2;
	}
	else {
		M_operate(value2);
	}

	flag = 1;
	step = 1;

	GetDlgItemText(IDC_EDIT1, str2);
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + str2 + L"-");

	omg.Format(L"%f", value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(IDC_EDIT1, omg);
}


void Ccaculator4Dlg::OnBnClickedButtonmult()   //곱하기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;
	double value2;
	GetDlgItemText(IDC_EDIT1, omg);
	value2 = _wtof(omg);

	count++;
	if (count == 1) {
		value = value2;
	}
	else {
		M_operate(value2);
	}

	flag = 2;
	step = 1;

	GetDlgItemText(IDC_EDIT1, str2);
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + str2 + L"×");

	omg.Format(L"%f", value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(IDC_EDIT1, omg);
}


void Ccaculator4Dlg::OnBnClickedButtondiv()   //나누기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;
	double value2;
	GetDlgItemText(IDC_EDIT1, omg);
	value2 = _wtof(omg);

	count++;
	if (count == 1) {
		value = value2;
	}
	else {
		M_operate(value2);
	}

	flag = 3;
	step = 1;

	GetDlgItemText(IDC_EDIT1, str2);
	GetDlgItemText(IDC_EDIT2, str);
	SetDlgItemText(IDC_EDIT2, str + str2 + L"÷");

	omg.Format(L"%f", value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(IDC_EDIT1, omg);
}


void Ccaculator4Dlg::OnBnClickedButtoneql()    // =버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	double value2;
	GetDlgItemText(IDC_EDIT1, str);
	value2 = _wtof(str);

	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit2->SetWindowTextW(L"");

	M_operate(value2);

	count = 0;

	str.Format(L"%f", value);
	str.TrimRight(L"0");
	str.TrimRight(L".");
	SetDlgItemText(IDC_EDIT1, str);
}


void Ccaculator4Dlg::OnBnClickedButtonclear()   // CE 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT1, L"");
}


void Ccaculator4Dlg::OnBnClickedButtondot()   // 소수점 추가
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + '.');
}


void Ccaculator4Dlg::OnBnClickedButtonbackspace()   // back space 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	str.Delete(str.GetLength()-1, 1);
	SetDlgItemText(IDC_EDIT1, str);
}


void Ccaculator4Dlg::OnBnClickedButtonroot()   // √연산
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString str, omg;
	double value2;
	GetDlgItemText(IDC_EDIT1, omg);
	value2 = _wtof(omg);

	omg.Format(L"%f", sqrt(value2));
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(IDC_EDIT1, omg);

	UpdateData(FALSE);
}


void Ccaculator4Dlg::OnBnClickedButtonzeagop()   // 제곱 연산
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString str, omg;
	double value2;
	GetDlgItemText(IDC_EDIT1, omg);
	value2 = _wtof(omg);

	omg.Format(L"%f", value2 * value2);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(IDC_EDIT1, omg);

	UpdateData(FALSE);
}


void Ccaculator4Dlg::OnBnClickedButtonboonsoo()   // 분수
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString str, omg;
	double value2;
	GetDlgItemText(IDC_EDIT1, omg);
	value2 = _wtof(omg);

	omg.Format(L"%f", 1/value2);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(IDC_EDIT1, omg);

	UpdateData(FALSE);
}


void Ccaculator4Dlg::OnBnClickedButtonallclear()   // C 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->SetWindowTextW(L"");

	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	pEdit2->SetWindowTextW(L"");

	value = 0;
	step = 0;
	flag = 0;
	count = 0;

	UpdateData(FALSE);
}


void Ccaculator4Dlg::OnBnClickedButtonplma()   // ± 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString omg;
	double value2;
	GetDlgItemText(IDC_EDIT1, omg);
	value2 = _wtof(omg);

	omg.Format(L"%f", -1 * value2);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(IDC_EDIT1, omg);

	UpdateData(FALSE);
}


void Ccaculator4Dlg::OnBnClickedButtonpersent()   // % 연산
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString omg;
	double value2;
	GetDlgItemText(IDC_EDIT1, omg);
	value2 = _wtof(omg);

	
	omg.Format(L"%f", value*(value2 / 100));
	omg.TrimRight(L"0");
	omg.TrimRight(L".");

	SetDlgItemText(IDC_EDIT1, omg);

	UpdateData(FALSE);

}
