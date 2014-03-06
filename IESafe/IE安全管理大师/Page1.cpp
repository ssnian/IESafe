// Page1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IE��ȫ�����ʦ.h"
#include "Page1.h"
#include "afxdialogex.h"


// CPage1 �Ի���

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


// CPage1 ��Ϣ�������


void CPage1::OnBnClickedButton6()    //��Ӱ�ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString URL;
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(URL);
	if(URL != "")
	{
		m_list1.AddString(URL);
		m_list1.SetCurSel(m_list1.GetCount() - 1);
	}
}


void CPage1::OnBnClickedButton5()        //ɾ����ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nCurSel;
	if((nCurSel = m_list1.GetCurSel()) != LB_ERR)
		m_list1.DeleteString(nCurSel);
}


void CPage1::OnBnClickedButton4()           //�޸İ�ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CPage1::OnBnClickedButton3()           //����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CPage1::OnBnClickedButton2()          //����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CPage1::OnBnClickedButton7()         //��������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

//IE���ڱ���
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
//Ĭ������·��
	CString strPath;
	GetDlgItem(IDC_EDIT3)->GetWindowTextW(strPath);
	mkey.Open(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main");
	mkey.SetStringValue(L"Default Download Directory", strPath);
	mkey.Close();

	MessageBox(L"�޸��ѱ���", L"֪ͨ", MB_OK);
}

void CPage1::OnBnClickedButton1()     //�������
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CPage1::OnLbnSelchangeList1()       //���ĳ��ַ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BROWSEINFO bi;
    WCHAR Buffer[MAX_PATH];
    //��ʼ����ڲ���bi��ʼ
    bi.hwndOwner = NULL;
    bi.pidlRoot = NULL;
    bi.pszDisplayName = Buffer;//�˲�����ΪNULL������ʾ�Ի���
    bi.lpszTitle = L"��ѡ���ļ���";
    bi.ulFlags = 0;
    bi.lpfn = NULL;
    //��ʼ����ڲ���bi����
    LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//������ʾѡ��Ի���
	bool hadGet = false;
    if(pIDList)
	{
		hadGet = (bool)SHGetPathFromIDList(pIDList,Buffer);
       //ȡ���ļ���·����Buffer��
     // m_ctrbrowse.SetWindowText(Buffer);//��·��������һ��CString������
	}
	//MessageBox((LPCTSTR)Buffer, L"f");
	if(hadGet)
		GetDlgItem(IDC_EDIT3)->SetWindowTextW(Buffer);
    LPMALLOC lpMalloc;
    if(FAILED(SHGetMalloc(&lpMalloc))) return;
    //�ͷ��ڴ�
    lpMalloc->Free(pIDList);
    lpMalloc->Release();
}
