
// calcuatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calcuator.h"
#include "calcuatorDlg.h"
#include "afxdialogex.h"
#include<math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalcuatorDlg 对话框




CcalcuatorDlg::CcalcuatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalcuatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	c=180;
	c1=174;
	c2=180;
	c3=174;
	c4=180;
	c5=174;
}

void CcalcuatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CcalcuatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CcalcuatorDlg::OnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalcuatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalcuatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalcuatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalcuatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalcuatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalcuatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalcuatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalcuatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_DOT, &CcalcuatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_0, &CcalcuatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_ADD, &CcalcuatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_MULTIPLY, &CcalcuatorDlg::OnBnClickedMultiply)
	ON_BN_CLICKED(IDC_SUBTRACTION, &CcalcuatorDlg::OnBnClickedSubtraction)
	ON_BN_CLICKED(IDC_CALCUATOR, &CcalcuatorDlg::OnBnClickedCalcuator)
	ON_BN_CLICKED(IDC_DIVIDE, &CcalcuatorDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_CLEAR, &CcalcuatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_MINUS, &CcalcuatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_BACKSPACE, &CcalcuatorDlg::OnBnClickedBackspace)
	ON_BN_CLICKED(IDC_SIN, &CcalcuatorDlg::OnBnClickedSin)
	ON_BN_CLICKED(IDC_COS, &CcalcuatorDlg::OnBnClickedCos)
	ON_BN_CLICKED(IDC_TAN, &CcalcuatorDlg::OnBnClickedTan)
	ON_BN_CLICKED(IDC_RADICAL, &CcalcuatorDlg::OnBnClickedRadical)
	ON_BN_CLICKED(IDC_PERCENT, &CcalcuatorDlg::OnBnClickedPercent)
	ON_BN_CLICKED(IDC_RECIPROCAL, &CcalcuatorDlg::OnBnClickedReciprocal)
	ON_BN_CLICKED(IDC_SQUARE, &CcalcuatorDlg::OnBnClickedSquare)
	ON_WM_TIMER()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CcalcuatorDlg 消息处理程序

BOOL CcalcuatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,100,NULL);
	SetTimer(2,6000,NULL);
	SetTimer(3,36000,NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalcuatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalcuatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalcuatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalcuatorDlg::OnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedDot()//点
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp=_ttof(m_str);
	m_str=m_str+L".";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedAdd()//加法
{
	// TODO: 在此添加控件通知处理程序代码
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedMultiply()//乘法
{
	// TODO: 在此添加控件通知处理程序代码
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedSubtraction()//减法
{
	// TODO: 在此添加控件通知处理程序代码
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
    m_str="";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedCalcuator()//等号
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE(L"flag=%d",flag);
	UpdateData(true);
	if(flag==1)
	{
		temp=temp+_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==2)
	{
		temp=temp*_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==3)
	{
		temp=temp-_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==4)
	{
		if(_ttof(m_str)==0)
		{
			m_str.Format(L"除数不能为零");
		}
		else
		{
			temp=temp/_ttof(m_str);
			m_str.Format(L"%lf",temp);
		}	
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedDivide()//除法
{
	// TODO: 在此添加控件通知处理程序代码
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedClear()//消除
{
	// TODO: 在此添加控件通知处理程序代码
	m_str="";
	UpdateData(false);
}

void CcalcuatorDlg::OnBnClickedMinus()//负号
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp=_ttof(m_str);
	m_str=L"-"+m_str;
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedBackspace()//退格
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedSin()//sin
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=sin(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedCos()//cos
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=cos(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedTan()//tan
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=tan(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedRadical()//根号
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=sqrt(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedPercent()//百分号
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=temp/100;
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}


void CcalcuatorDlg::OnBnClickedReciprocal()//倒数
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	if(temp==0)
	{
		m_str.Format(L"error");
	}
	else
	{
		temp=1/temp;
		m_str.Format(L"%lf",temp);
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalcuatorDlg::OnBnClickedSquare()//平方
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=pow(temp,2);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalcuatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	    int x,y,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,ox=450,oy=200;
		if(nIDEvent==1)
		{
			int r=80;
			CDC *pDC;
            CPen newpen,*oldpen;
	        newpen.CreatePen(PS_SOLID,2,RGB(240,240,240));
	        pDC=GetDC();
	        oldpen=pDC->SelectObject(&newpen);
		    x=ox+r*sin(c*3.1415926/180);
		    y=oy+r*cos(c*3.1415926/180);
		    pDC->MoveTo(ox,oy);
		    pDC->LineTo(x,y);
		    c=c-6;
		    CDC *pDC1;
		    CPen newpen1,*oldpen1;
		    newpen1.CreatePen(PS_SOLID,2,RGB(0,0,0));
		    pDC1=GetDC();
		    oldpen1=pDC1->SelectObject(&newpen1);
		    x1=ox+r*sin(c1*3.1415926/180);
		    y1=oy+r*cos(c1*3.1415926/180);
		    pDC1->MoveTo(ox,oy);
		    pDC1->LineTo(x1,y1);
		    c1=c1-6;
		}
		if(nIDEvent==2)
		{
			int r=60;
			CDC *pDC2;
			CPen newpen2,*oldpen2;
			newpen2.CreatePen(PS_SOLID,2,RGB(240,240,240));
			pDC2=GetDC();
			oldpen2=pDC2->SelectObject(&newpen2);
			x2=ox+r*sin(c2*3.1415926/180/60);
		    y2=oy+r*cos(c2*3.1415926/180/60);
		    pDC2->MoveTo(ox,oy);
		    pDC2->LineTo(x2,y2);
		    c2=c2-6;
			CDC *pDC3;
			CPen newpen3,*oldpen3;
			newpen3.CreatePen(PS_SOLID,2,RGB(0,0,0));
			pDC3=GetDC();
			oldpen3=pDC3->SelectObject(&newpen3);
			x3=ox+r*sin(c3*3.1415926/180);
		    y3=oy+r*cos(c3*3.1415926/180);
		    pDC3->MoveTo(ox,oy);
		    pDC3->LineTo(x3,y3);
		    c3=c3-6;
		}
		if(nIDEvent==3)
		{
			int r=65;
			CDC *pDC4;
			CPen newpen4,*oldpen4;
			newpen4.CreatePen(PS_SOLID,2,RGB(240,240,240));
			pDC4=GetDC();
			oldpen4=pDC4->SelectObject(&newpen4);
			x4=ox+r*sin(c4*3.1415926/180);
		    y4=oy+r*cos(c4*3.1415926/180);
		    pDC4->MoveTo(ox,oy);
		    pDC4->LineTo(x2,y2);
		    c4=c4-6;
			CDC *pDC5;
			CPen newpen5,*oldpen5;
			newpen5.CreatePen(PS_SOLID,2,RGB(0,0,0));
			pDC5=GetDC();
			oldpen5=pDC5->SelectObject(&newpen5);
			x5=ox+r*sin(c5*3.1415926/180);
		    y5=oy+r*cos(c5*3.1415926/180);
		    pDC5->MoveTo(ox,oy);
		    pDC5->LineTo(x5,y5);
		    c5=c5-6;
		}
		    CDialogEx::OnTimer(nIDEvent);
}

void CcalcuatorDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
}
