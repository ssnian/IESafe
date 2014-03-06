
// IE安全管理大师Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IE安全管理大师.h"
#include "IE安全管理大师Dlg.h"
#include "afxdialogex.h"

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


// CIE安全管理大师Dlg 对话框



CIE安全管理大师Dlg::CIE安全管理大师Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIE安全管理大师Dlg::IDD, pParent)
	, m_CurSelTab(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIE安全管理大师Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CIE安全管理大师Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CIE安全管理大师Dlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CIE安全管理大师Dlg 消息处理程序

BOOL CIE安全管理大师Dlg::OnInitDialog()
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
	//为Tab Control增加两个页面
	m_tab.InsertItem(0, _T("常规"));
	m_tab.InsertItem(1, _T("属性设置")); 
	m_tab.InsertItem(2, _T("安全设置")); 
	m_tab.InsertItem(3, _T("IE右键菜单")); 
	//创建两个对话框
	m_page1.Create(IDD_DIALOG1, &m_tab);
	m_page2.Create(IDD_DIALOG2, &m_tab);
	m_page3.Create(IDD_DIALOG3, &m_tab);
	m_page4.Create(IDD_DIALOG4, &m_tab);
	//设定在Tab内显示的范围
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	m_page1.MoveWindow(&rc);
	m_page2.MoveWindow(&rc); 
	m_page3.MoveWindow(&rc); 
	m_page4.MoveWindow(&rc); 
	//把对话框对象指针保存起来
	pDialog[0] = &m_page1;
	pDialog[1] = &m_page2;
	pDialog[2] = &m_page3;
	pDialog[3] = &m_page4;
	//显示初始页面
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	pDialog[2]->ShowWindow(SW_HIDE);
	pDialog[3]->ShowWindow(SW_HIDE);
	//保存当前选择
	m_CurSelTab = 0;

	//获取当前主页 //
	CRegKey key; 
	ULONG longg;
	WCHAR URL[512];
	HKEY hkey;
	DWORD type, length;
	RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
	RegQueryValueEx(hkey, L"Start Page", 0, &type, (LPBYTE)URL, &length);
	m_page1.m_list1.AddString(URL);
	lstrcpy(URL, L"");

	key.Open(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main");
	key.QueryMultiStringValue(L"Secondary Start Pages", URL, &longg);
	
	int len = 0;
	bool is = true;
	while(is)
	{
		if(URL[len] >= L'a' && URL[len] <= L'z' || URL[len] >= L'A' && URL[len] <= L'Z')
		{
			m_page1.m_list1.AddString(URL + len);
			len += lstrlen(URL) + 1;
		}
		else
			is = false;
	}
	RegCloseKey(hkey);
	key.Close();

	m_page4.m_list1.InsertColumn(0, L"右键名称", LVCFMT_LEFT, 300);
	m_page4.m_list1.InsertColumn(1, L"状态", LVCFMT_LEFT, 150);
	DWORD dwStyle = m_page4.m_list1.GetExtendedStyle();
	dwStyle |= LVS_EX_GRIDLINES;
	m_page4.m_list1.SetExtendedStyle(dwStyle);

	CRegKey rr;
	rr.Open(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\MenuExt");
	DWORD index = 0;
	for(DWORD i = 0; ; i++)
	{
		WCHAR regPath[256];
		DWORD length = 999999;

		if(rr.EnumKey(i, regPath, &length))
			break;
		
		m_page4.m_list1.InsertItem(m_page4.m_list1.GetCountPerPage(), regPath);
		CString tt = L"Software\\Microsoft\\Internet Explorer\\MenuExt\\";
		tt += regPath;
		CRegKey tReg;
		tReg.Open(HKEY_CURRENT_USER, tt);
		DWORD value = 9999;

		tReg.QueryValue(L"", NULL, regPath, &value);
		if(regPath[0] == '-')
			m_page4.m_list1.SetItemText(i, 1, L"禁用");
		else
			m_page4.m_list1.SetItemText(i, 1, L"启用");
		tReg.Close();
	}
	rr.Close();
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CIE安全管理大师Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIE安全管理大师Dlg::OnPaint()
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
HCURSOR CIE安全管理大师Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIE安全管理大师Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	//把当前的页面隐藏起来    
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);    
	//得到新的页面索引    
	m_CurSelTab = m_tab.GetCurSel();    
	//把新的页面显示出来    
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);    
	*pResult = 0;
}
