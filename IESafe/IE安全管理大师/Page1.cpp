// Page1.cpp : 实现文件
//

#include "stdafx.h"
#include "IE安全管理大师.h"
#include "Page1.h"
#include "afxdialogex.h"


// CPage1 对话框

IMPLEMENT_DYNAMIC(CPage1, CDialogEx)

CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage1::IDD, pParent)
{

}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(CPage1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &CPage1::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CPage1::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CPage1::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CPage1::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CPage1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON71, &CPage1::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &CPage1::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CPage1::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON8, &CPage1::OnBnClickedButton8)
END_MESSAGE_MAP()


// CPage1 消息处理程序


void CPage1::OnBnClickedButton6()    //添加按钮
{
	// TODO: 在此添加控件通知处理程序代码
	CString URL;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(URL);
	if(URL != "")
	{
		m_list1.AddString(URL);
		m_list1.SetCurSel(m_list1.GetCount() - 1);
	}
}


void CPage1::OnBnClickedButton5()        //删除按钮
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel;
	if((nCurSel = m_list1.GetCurSel()) != LB_ERR)
		m_list1.DeleteString(nCurSel);
}


void CPage1::OnBnClickedButton4()           //修改按钮
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel;
	CString URL;
	if((nCurSel = m_list1.GetCurSel()) != LB_ERR)
	{
		GetDlgItem(IDC_EDIT1)->GetWindowTextW(URL);
		m_list1.DeleteString(nCurSel);
		m_list1.InsertString(nCurSel, URL);
	}
	m_list1.SetCurSel(nCurSel);
	UpdateData();
}


void CPage1::OnBnClickedButton3()           //上移
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel;
	CString URL;
	if((nCurSel = m_list1.GetCurSel()) != LB_ERR)
	{
		if(nCurSel > 0)
		{
			m_list1.GetText(nCurSel, URL);
			m_list1.DeleteString(nCurSel);
			m_list1.InsertString(nCurSel - 1, URL);
		}
	}
	m_list1.SetCurSel(nCurSel - 1);
}


void CPage1::OnBnClickedButton2()          //下移
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel;
	CString URL;
	if((nCurSel = m_list1.GetCurSel()) != LB_ERR)
	{
		if(nCurSel < m_list1.GetCount() - 1)
		{
			m_list1.GetText(nCurSel, URL);
			m_list1.DeleteString(nCurSel);
			m_list1.InsertString(nCurSel + 1, URL);
		}
	}
	m_list1.SetCurSel(nCurSel + 1);
}


void CPage1::OnBnClickedButton7()         //保存设置
{
	// TODO: 在此添加控件通知处理程序代码
	WCHAR URL[5120];
	WCHAR temp[512];
	m_list1.GetText(0, URL);
	HKEY hkey;

	RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
	RegSetValueEx(hkey, L"Start Page", 0, REG_SZ, (LPBYTE)URL, lstrlenW(URL) * sizeof(WCHAR));

	RegCloseKey(hkey);

	if(m_list1.GetCount() > 1)
	{
		RegCreateKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		m_list1.GetText(1, URL);
		int len = lstrlen(URL) + 1;
		for(int i = 2; i < m_list1.GetCount(); i++)
		{
			m_list1.GetText(i, temp);
			lstrcpy(URL + len, temp);
			int tempLen = lstrlen(temp);
			len += tempLen + 1;
		}
		RegSetValueEx(hkey, L"Secondary Start Pages", 0, REG_MULTI_SZ, (LPBYTE)URL, len * sizeof(WCHAR));
	}
	else
	{
		RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", L"Secondary Start Pages");
	}

//IE窗口标题
	CString strTitle;
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(strTitle);
	CRegKey mkey;
	if(!mkey.Open(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main"))
	{
		mkey.Create(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main");
	}
	if(strTitle == "")
	{
		mkey.DeleteValue(L"Window Title");
	}
	else
		mkey.SetStringValue(L"Window Title", strTitle);
	mkey.Close();
//默认下载路径
	CString strPath;
	GetDlgItem(IDC_EDIT3)->GetWindowTextW(strPath);
	mkey.Open(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main");
	mkey.SetStringValue(L"Default Download Directory", strPath);
	mkey.Close();

	MessageBox(L"修改已保存", L"通知", MB_OK);
}

void CPage1::OnBnClickedButton1()     //设置最佳
{
	// TODO: 在此添加控件通知处理程序代码
	WCHAR URL[512] = L"www.baidu.com";
	HKEY hkey;

	RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
	RegSetValueEx(hkey, L"Start Page", 0, REG_SZ, (LPBYTE)URL, lstrlenW(URL) * sizeof(WCHAR));

	RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", L"Secondary Start Pages");

	RegCloseKey(hkey);

	while(m_list1.GetCount() > 0)
		m_list1.DeleteString(0);
	m_list1.AddString(L"www.baidu.com");
	UpdateData();
}


void CPage1::OnLbnSelchangeList1()       //点击某网址
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel;
	CString URL;
	if((nCurSel = m_list1.GetCurSel()) != LB_ERR)
	{
		m_list1.GetText(nCurSel, URL);
		GetDlgItem(IDC_EDIT1)->SetWindowTextW(URL);
	}
	UpdateData();
}


void CPage1::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	BROWSEINFO bi;
    WCHAR Buffer[MAX_PATH];
    //初始化入口参数bi开始
    bi.hwndOwner = NULL;
    bi.pidlRoot = NULL;
    bi.pszDisplayName = Buffer;//此参数如为NULL则不能显示对话框
    bi.lpszTitle = L"请选择文件夹";
    bi.ulFlags = 0;
    bi.lpfn = NULL;
    //初始化入口参数bi结束
    LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//调用显示选择对话框
	bool hadGet = false;
    if(pIDList)
	{
		hadGet = (bool)SHGetPathFromIDList(pIDList,Buffer);
       //取得文件夹路径到Buffer里
     // m_ctrbrowse.SetWindowText(Buffer);//将路径保存在一个CString对象里
	}
	//MessageBox((LPCTSTR)Buffer, L"f");
	if(hadGet)
		GetDlgItem(IDC_EDIT3)->SetWindowTextW(Buffer);
    LPMALLOC lpMalloc;
    if(FAILED(SHGetMalloc(&lpMalloc))) return;
    //释放内存
    lpMalloc->Free(pIDList);
    lpMalloc->Release();
}
