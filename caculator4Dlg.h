
// caculator4Dlg.h: 헤더 파일
//

#pragma once


// Ccaculator4Dlg 대화 상자
class Ccaculator4Dlg : public CDialogEx
{
private:
	char flag = 0;       // Plus:0 , minu:1 , mult:2, div:3
	char step = 0;       // 연산자 확인변수
	int count = 0;       // 연산자 카운트변수
	double value = 0;    // 숫자값을 저장하기 위한 변수
public:
	void M_operate(double value2); // 사칙연산 추가함수
	// 생성입니다.
	Ccaculator4Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CACULATOR4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedButtonplu();
	afx_msg void OnBnClickedButtonminu();
	afx_msg void OnBnClickedButtonmult();
	afx_msg void OnBnClickedButtondiv();
	afx_msg void OnBnClickedButtoneql();
	afx_msg void OnBnClickedButtonclear();
	afx_msg void OnBnClickedButtondot();
	afx_msg void OnBnClickedButtonbackspace();
	afx_msg void OnBnClickedButtonroot();
	afx_msg void OnBnClickedButtonzeagop();
	afx_msg void OnBnClickedButtonboonsoo();
	afx_msg void OnBnClickedButtonallclear();
	afx_msg void OnBnClickedButtonplma();
	afx_msg void OnBnClickedButtonpersent();
};
