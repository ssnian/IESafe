// Page3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IE��ȫ�����ʦ.h"
#include "Page3.h"
#include "afxdialogex.h"


// CPage3 �Ի���

IMPLEMENT_DYNAMIC(CPage3, CDialogEx)

CPage3::CPage3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage3::IDD, pParent)
{

}

CPage3::~CPage3()
{
}

void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON73, &CPage3::OnBnClickedButton73)
END_MESSAGE_MAP()


// CPage3 ��Ϣ�������


void CPage3::OnBnClickedButton73()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())             //����Internet������
	{
		HKEY hkey;
		DWORD value = 1;

		RegCreateKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Control Panel", &hkey);
		RegSetValueEx(hkey, L"Connwiz Admin Lock", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Control Panel", L"Connwiz Admin Lock");
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())             //����IE����������ع���
	{
		DWORD value = 3;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\Zones\\3", &hkey);
		RegSetValueEx(hkey, L"1803", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())
	{
		DWORD value = 0;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\Zones\\3", &hkey);
		RegSetValueEx(hkey, L"1803", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())             //��ֹ�ı䵯��������ֹ����ļ���
	{
		HKEY hkey;
		DWORD value = 1;

		RegCreateKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"DisablePopupFilterLevel", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
	{
		RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions", L"DisablePopupFilterLevel");
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())             //�رհ�ȫ�������
	{
		HKEY hkey;
		DWORD value = 1;

		RegCreateKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Security", &hkey);
		RegSetValueEx(hkey, L"DisableSecuritySettingsCheck", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())
	{
		RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Security", L"DisableSecuritySettingsCheck");
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())             //���ñ���д�Զ���ɹ���
	{
		HKEY hkey;
		DWORD value = 1;

		RegCreateKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Control Panel", &hkey);
		RegSetValueEx(hkey, L"FormSuggest", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())
	{
		RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Control Panel", L"FormSuggest");
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())             //��ֹ���뼰�����ղؼ�
	{
		DWORD value = 1;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer", &hkey);
		RegSetValueEx(hkey, L"DisableImportExportFavorites", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())
	{
		DWORD value = 0;

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer", &hkey);
		RegSetValueEx(hkey, L"DisableImportExportFavorites", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())             //��ֹ�����ɾ����ʷ��¼�Ĺ���
	{
		HKEY hkey;
		DWORD value = 1;

		RegCreateKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Control Panel", &hkey);
		RegSetValueEx(hkey, L"DisableDeleteBrowsingHistory", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())
	{
		RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Control Panel", L"DisableDeleteBrowsingHistory");
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())             //�Զ��������ڹ������
	{
		WCHAR URL[512] = L"yes";

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\New Windows", &hkey);
		RegSetValueEx(hkey, L"PopupMgr", 0, REG_SZ, (LPBYTE)URL, 6);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())
	{
		WCHAR URL[512] = L"no";

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\New Windows", &hkey);
		RegSetValueEx(hkey, L"PopupMgr", 0, REG_SZ, (LPBYTE)URL, 4);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())             //��ֹ����IE������
	{
		HKEY hkey;
		DWORD value = 1;

		RegCreateKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions", &hkey);
		RegSetValueEx(hkey, L"NoExtensionManagement", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())
	{
		RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Restrictions", L"NoExtensionManagement");
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())             //�������е��������
	{
		WCHAR URL[512] = L"no";

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"Enable Browser Extensions", 0, REG_SZ, (LPBYTE)URL, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())
	{
		WCHAR URL[512] = L"yes";

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"Enable Browser Extensions", 0, REG_SZ, (LPBYTE)URL, 6);

		RegCloseKey(hkey);
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())             //���û�ԭ��IEĬ������
	{
		HKEY hkey;
		DWORD value = 1;

		RegCreateKey(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Control Panel", &hkey);
		RegSetValueEx(hkey, L"DisableRIED", 0, REG_DWORD, (LPBYTE)&value, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())
	{
		RegDeleteKeyValue(HKEY_CURRENT_USER, L"Software\\Policies\\Microsoft\\Internet Explorer\\Control Panel", L"DisableRIED");
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())             //������ҳ�ű�����
	{
		WCHAR URL[512] = L"no";

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"Disable Script Debugger", 0, REG_SZ, (LPBYTE)URL, 4);

		RegCloseKey(hkey);
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())
	{
		WCHAR URL[512] = L"yes";

		HKEY hkey;
		RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\Main", &hkey);
		RegSetValueEx(hkey, L"Disable Script Debugger", 0, REG_SZ, (LPBYTE)URL, 6);

		RegCloseKey(hkey);
	}

	MessageBox(L"�޸��ѱ���", L"֪ͨ", MB_OK);

}
