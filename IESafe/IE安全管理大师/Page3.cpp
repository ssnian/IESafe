// Page3.cpp : 实现文件
//

#include "stdafx.h"
#include "IE安全管理大师.h"
#include "Page3.h"
#include "afxdialogex.h"


// CPage3 对话框

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


// CPage3 消息处理程序


void CPage3::OnBnClickedButton73()
{
	// TODO: 在此添加控件通知处理程序代码

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())             //禁用Internet连接向导
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())             //禁用IE浏览器的下载功能
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())             //禁止改变弹出窗口阻止程序的级别
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())             //关闭安全检查特性
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())             //禁用表单填写自动完成功能
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())             //禁止导入及到处收藏夹
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())             //禁止浏览器删除历史记录的功能
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())             //自动弹出窗口管理程序
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())             //禁止启用IE加载项
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())             //禁用所有第三方插件
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())             //禁用还原到IE默认设置
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())             //启用网页脚本调试
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

	MessageBox(L"修改已保存", L"通知", MB_OK);

}
