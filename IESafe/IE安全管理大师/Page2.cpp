// Page2.cpp : 实现文件
//

#include "stdafx.h"
#include "IE安全管理大师.h"
#include "Page2.h"
#include "afxdialogex.h"


// CPage2 对话框

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


// CPage2 消息处理程序


void CPage2::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())             //禁用标签式浏览
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck())             //用新的进程加载IE窗口
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())             //收藏夹条目自动排序
	{
		
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck())
	{
		
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck())             //禁用图像自动缩放
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck())             //在新标签中打开网页
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck())             //打开地址栏自动完成功能
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck())             //只显示最常用的收藏
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())             //禁止修改IE命令栏
	{
		
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck())
	{
		
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())             //在程序中点击链接打开新的IE窗口
	{
		
	}
	else if(BST_UNCHECKED==((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck())
	{
		
	}

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck())             //关闭IE时自动清理缓存文件
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck())             //禁止查看网页源代码
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck())             //禁止保存下载文件
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck())             //隐藏IE的公共栏
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck())             //显示菜单栏
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK15))->GetCheck())             //隐藏IE的导航栏
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK16))->GetCheck())             //隐藏IE的搜索框
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK17))->GetCheck())             //把菜单移到导航栏的上方
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK18))->GetCheck())             //IE窗口全屏浏览
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK19))->GetCheck())             //禁用RSS订阅检测
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK20))->GetCheck())             //禁用RSS订阅列表
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK21))->GetCheck())             //禁止添加或删除RSS订阅
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

	if(BST_CHECKED==((CButton*)GetDlgItem(IDC_CHECK22))->GetCheck())             //当找到RSS订阅时自动播放声音
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

	MessageBox(L"修改已保存", L"通知", MB_OK);
}
