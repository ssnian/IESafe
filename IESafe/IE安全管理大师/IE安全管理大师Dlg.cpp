
// IE��ȫ�����ʦDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IE��ȫ�����ʦ.h"
#include "IE��ȫ�����ʦDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CIE��ȫ�����ʦDlg �Ի���



CIE��ȫ�����ʦDlg::CIE��ȫ�����ʦDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIE��ȫ�����ʦDlg::IDD, pParent)
	, m_CurSelTab(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIE��ȫ�����ʦDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}

BEGIN_MESSAGE_MAP(CIE��ȫ�����ʦDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CIE��ȫ�����ʦDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CIE��ȫ�����ʦDlg ��Ϣ�������

BOOL CIE��ȫ�����ʦDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//ΪTab Control��������ҳ��
	m_tab.InsertItem(0, _T("����"));
	m_tab.InsertItem(1, _T("��������")); 
	m_tab.InsertItem(2, _T("��ȫ����")); 
	m_tab.InsertItem(3, _T("IE�Ҽ��˵�")); 
	//���������Ի���
	m_page1.Create(IDD_DIALOG1, &m_tab);
	m_page2.Create(IDD_DIALOG2, &m_tab);
	m_page3.Create(IDD_DIALOG3, &m_tab);
	m_page4.Create(IDD_DIALOG4, &m_tab);
	//�趨��Tab����ʾ�ķ�Χ
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
	//�ѶԻ������ָ�뱣������
	pDialog[0] = &m_page1;
	pDialog[1] = &m_page2;
	pDialog[2] = &m_page3;
	pDialog[3] = &m_page4;
	//��ʾ��ʼҳ��
	pDialog[0]->ShowWindow(SW_SHOW);
	pDialog[1]->ShowWindow(SW_HIDE);
	pDialog[2]->ShowWindow(SW_HIDE);
	pDialog[3]->ShowWindow(SW_HIDE);
	//���浱ǰѡ��
	m_CurSelTab = 0;

	//��ȡ��ǰ��ҳ //
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

	m_page4.m_list1.InsertColumn(0, L"�Ҽ�����", LVCFMT_LEFT, 300);
	m_page4.m_list1.InsertColumn(1, L"״̬", LVCFMT_LEFT, 150);
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
			m_page4.m_list1.SetItemText(i, 1, L"����");
		else
			m_page4.m_list1.SetItemText(i, 1, L"����");
		tReg.Close();
	}
	rr.Close();
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CIE��ȫ�����ʦDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CIE��ȫ�����ʦDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CIE��ȫ�����ʦDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIE��ȫ�����ʦDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	//�ѵ�ǰ��ҳ����������    
	pDialog[m_CurSelTab]->ShowWindow(SW_HIDE);    
	//�õ��µ�ҳ������    
	m_CurSelTab = m_tab.GetCurSel();    
	//���µ�ҳ����ʾ����    
	pDialog[m_CurSelTab]->ShowWindow(SW_SHOW);    
	*pResult = 0;
}
