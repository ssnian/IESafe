// Page2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IE��ȫ�����ʦ.h"
#include "Page2.h"
#include "afxdialogex.h"


// CPage2 �Ի���

IMPLEMENT_DYNAMIC(CPage2, CDialogEx)

CPage2::CPage2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage2::IDD, pParent)
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON72, &CPage2::OnBnClickedButton7)
END_MESSAGE_MAP()


// CPage2 ��Ϣ�������


void CPage2::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())             //���ñ�ǩʽ���
	{
		DWORD value = 0;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\TabbedBrowsing", &hkey);
		RegSetValueEx(hkey, L"Enabled", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		DWORD value = 1;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\TabbedBrowsing", &hkey);
		RegSetValueEx(hkey, L"Enabled", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())             //���µĽ��̼���IE����
	{
		WCHAR URL[512] = L"yes";

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\BrowseNewProcess", &hkey);
		RegSetValueEx(hkey, L"BrowseNewProcess", 0, REG_SZ, (LPBYTE)URL, 6);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())
	{
		WCHAR URL[512] = L"no";
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\BrowseNewProcess", &hkey);
		RegSetValueEx(hkey, L"BrowseNewProcess", 0, REG_SZ, (LPBYTE)URL, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())             //�ղؼ���Ŀ�Զ�����
	{
		
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
	{
		
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())             //����ͼ���Զ�����
	{
		wchar_t URL[512]= L"no";
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"Enable AutoImageResize", 0, REG_SZ, (LPBYTE)URL, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())
	{
		wchar_t URL[512]= L"yes";
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"Enable AutoImageResize", 0, REG_SZ, (LPBYTE)URL, 6);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())             //���±�ǩ�д���ҳ
	{
		DWORD value = 2;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\TabbedBrowsing", &hkey);
		RegSetValueEx(hkey, L"PopupsUseNewWindow", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())
	{
		DWORD value = 1;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\TabbedBrowsing", &hkey);
		RegSetValueEx(hkey, L"PopupsUseNewWindow", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())             //�򿪵�ַ���Զ���ɹ���
	{
		WCHAR URL[512] = L"yes";
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\AutoComplete", &hkey);
		RegSetValueEx(hkey, L"AutoSuggest", 0, REG_SZ, (LPBYTE)URL, 6);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())
	{
		WCHAR URL[512] = L"no";
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\AutoComplete", &hkey);
		RegSetValueEx(hkey, L"AutoSuggest", 0, REG_SZ, (LPBYTE)URL, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())             //ֻ��ʾ��õ��ղ�
	{
		wchar_t URL[512]=L"yes";
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"FavIntelliMenus", 0, REG_SZ, (LPBYTE)URL, 6);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())
	{
		wchar_t URL[512]=L"no";
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"FavIntelliMenus", 0, REG_SZ, (LPBYTE)URL, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())             //��ֹ�޸�IE������
	{
		
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())
	{
		
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())             //�ڳ����е�����Ӵ��µ�IE����
	{
		
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())
	{
		
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())             //�ر�IEʱ�Զ��������ļ�
	{
		DWORD value=0;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\CACHE", &hkey);
		RegSetValueEx(hkey, L"Persistent", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())
	{
		DWORD value=1;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\CACHE", &hkey);
		RegSetValueEx(hkey, L"Persistent", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())             //��ֹ�鿴��ҳԴ����
	{
		DWORD value=1;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoViewSource", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())
	{
		DWORD value=0;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoViewSource", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())             //��ֹ���������ļ�
	{
		DWORD vaule= 1;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoSelectDownloadDir", 0, REG_DWORD, (LPBYTE)&vaule, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())
	{
		DWORD vaule= 0;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoSelectDownloadDir", 0, REG_DWORD, (LPBYTE)&vaule, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck())             //����IE�Ĺ�����
	{
		DWORD value = 1;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Toolbars\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoCommandBar", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck())
	{
		DWORD value = 0;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Toolbars\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoCommandBar", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck())             //��ʾ�˵���
	{
		DWORD value = 1;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\MINIE", &hkey);
		RegSetValueEx(hkey, L"AlwaysShowMenus", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck())
	{
		DWORD value = 0;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\MINIE", &hkey);
		RegSetValueEx(hkey, L"AlwaysShowMenus", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK15))->GetCheck())             //����IE�ĵ�����
	{
		DWORD value = 1;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Toolbars\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoNavBar", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK15))->GetCheck())
	{
		DWORD value = 0;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Toolbars\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoNavBar", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK16))->GetCheck())             //����IE��������
	{
		DWORD value = 1;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Infodelivery\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoSearchBox", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK16))->GetCheck())
	{
		DWORD value = 0;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Infodelivery\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoSearchBox", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK17))->GetCheck())             //�Ѳ˵��Ƶ����������Ϸ�
	{
		DWORD value = 1;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Toolbar\\WebBrowser", &hkey);
		RegSetValueEx(hkey, L"ITBar7Position", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK17))->GetCheck())
	{
		DWORD value = 0;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Toolbar\\WebBrowser", &hkey);
		RegSetValueEx(hkey, L"ITBar7Position", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK18))->GetCheck())             //IE����ȫ�����
	{
		WCHAR URL[512] = L"yes";

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"FullScreen", 0, REG_SZ, (LPBYTE)URL, 6);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK18))->GetCheck())
	{
		WCHAR URL[512] = L"no";

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"FullScreen", 0, REG_SZ, (LPBYTE)URL, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK19))->GetCheck())             //����RSS���ļ��
	{
		DWORD value =0;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Feed Discovery", &hkey);
		RegSetValueEx(hkey, L"Enabled", 0, REG_SZ, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK19))->GetCheck())
	{
		DWORD value =1;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Feed Discovery", &hkey);
		RegSetValueEx(hkey, L"Enabled", 0, REG_SZ, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK20))->GetCheck())             //����RSS�����б�
	{
		DWORD value =1;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Feeds", &hkey);
		RegSetValueEx(hkey, L"DisableFeedPane", 0, REG_SZ, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK20))->GetCheck())
	{
		DWORD value =0;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Feeds", &hkey);
		RegSetValueEx(hkey, L"DisableFeedPane", 0, REG_SZ, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK21))->GetCheck())             //��ֹ��ӻ�ɾ��RSS����
	{
		DWORD value =1;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Feeds", &hkey);
		RegSetValueEx(hkey, L"DisableAddRemove", 0, REG_SZ, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK21))->GetCheck())
	{
		DWORD value =0;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Feeds", &hkey);
		RegSetValueEx(hkey, L"DisableAddRemove", 0, REG_SZ, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK22))->GetCheck())             //���ҵ�RSS����ʱ�Զ���������
	{
		DWORD value =1;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Feed Discovery", &hkey);
		RegSetValueEx(hkey, L"Sound", 0, REG_SZ, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK22))->GetCheck())
	{
		DWORD value =0;
		HKEY hkey;

		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Feed Discovery", &hkey);
		RegSetValueEx(hkey, L"Sound", 0, REG_SZ, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	MessageBox(L"�޸��ѱ���", L"֪ͨ", MB_OK);
}
