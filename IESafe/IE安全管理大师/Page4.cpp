// Page4.cpp : 实现文件
//

#include "stdafx.h"
#include "IE安全管理大师.h"
#include "Page4.h"
#include "afxdialogex.h"


// CPage4 对话框

IMPLEMENT_DYNAMIC(CPage4, CDialogEx)

CPage4::CPage4(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage4::IDD, pParent)
{

}

CPage4::~CPage4()
{
}

void CPage4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_LIST2, m_list2);
}


BEGIN_MESSAGE_MAP(CPage4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON74, &CPage4::OnBnClickedButton74)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CPage4::OnLvnItemchangedList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CPage4::OnNMClickList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CPage4::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPage4::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CPage4::OnBnClickedButton3)
END_MESSAGE_MAP()


// CPage4 消息处理程序


void CPage4::OnBnClickedButton74()
{
	// TODO: 在此添加控件通知处理程序代码

	MessageBox(L"修改已保存", L"通知", MB_OK);
}


void CPage4::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	

	*pResult = 0;
}


void CPage4::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
		*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	while(m_list2.GetCount() > 0)
		m_list2.DeleteString(0);
	int nCurSel;
	CString URL;
	POSITION ps = m_list1.GetFirstSelectedItemPosition();
	if((nCurSel = m_list1.GetNextSelectedItem(ps)) != LB_ERR)
	{
		CString str;
		str = m_list1.GetItemText(nCurSel, 0);

		CString tt = L"Software\\Microsoft\\Internet Explorer\\MenuExt\\";
		tt += str;
		CRegKey tReg;
		WCHAR buffer[256];
		tReg.Open(HKEY_CURRENT_USER, tt);
		DWORD value = 9999;

		tReg.QueryValue(L"", NULL, buffer, &value);
		CString temp = L"";
		str = temp + L"名称： " + str;
		m_list2.AddString(str);
		str = L"路径： ";
		if(buffer[0] == '-')
			str += buffer + 1;
		else
			str += buffer;
		m_list2.AddString(str);
		
		tReg.Close();
	}
	UpdateData();
	*pResult = 0;
}


void CPage4::OnBnClickedButton1()          //启用
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel;
	CString URL;
	POSITION ps = m_list1.GetFirstSelectedItemPosition();
	if((nCurSel = m_list1.GetNextSelectedItem(ps)) != LB_ERR)
	{
		CString str;
		str = m_list1.GetItemText(nCurSel, 0);
		//MessageBox(str);
		CString tt = L"Software\\Microsoft\\Internet Explorer\\MenuExt\\";
		tt += str;
		CRegKey tReg;
		WCHAR buffer[256];
		tReg.Open(HKEY_CURRENT_USER, tt);
		DWORD value = 9999;

		str = L"";
		tReg.QueryValue(L"", NULL, buffer, &value);
		if(buffer[0] == '-')
		{
			str += buffer + 1;
			m_list1.SetItemText(nCurSel, 1, L"启用");
		}
		else
		{
			str += buffer;
			m_list1.SetItemText(nCurSel, 1, L"启用");
		}
		tReg.SetValue(L"", REG_SZ, str, (ULONG)str.GetLength() * 2);
		
		tReg.Close();
	}
}


void CPage4::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel;
	CString URL;
	POSITION ps = m_list1.GetFirstSelectedItemPosition();
	if((nCurSel = m_list1.GetNextSelectedItem(ps)) != LB_ERR)
	{
		CString str;
		str = m_list1.GetItemText(nCurSel, 0);
		//MessageBox(str);
		CString tt = L"Software\\Microsoft\\Internet Explorer\\MenuExt\\";
		tt += str;
		CRegKey tReg;
		WCHAR buffer[256];
		tReg.Open(HKEY_CURRENT_USER, tt);
		DWORD value = 9999;

		str = L"";
		tReg.QueryValue(L"", NULL, buffer, &value);
		if(buffer[0] == '-')
		{
			str += buffer;
			m_list1.SetItemText(nCurSel, 1, L"禁用");
		}
		else
		{
			str += str + L"-" + buffer;
			m_list1.SetItemText(nCurSel, 1, L"禁用");
		}
		tReg.SetValue(L"", REG_SZ, str, (ULONG)str.GetLength() * 2);
		
		tReg.Close();
	}
}


void CPage4::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel;
	CString URL;
	POSITION ps = m_list1.GetFirstSelectedItemPosition();
	if((nCurSel = m_list1.GetNextSelectedItem(ps)) != LB_ERR)
	{
		CString str;
		str = m_list1.GetItemText(nCurSel, 0);
		//MessageBox(str);
		CRegKey rr;
		rr.Open(HKEY_CURRENT_USER, L"Software\\Microsoft\\Internet Explorer\\MenuExt");
		DWORD index = 0;
		for(DWORD i = 0; ; i++)
		{
			WCHAR regPath[256];
			DWORD length = 999999;

			if(rr.EnumKey(i, regPath, &length))
				break;
		
			if(str == regPath)
			{
				rr.DeleteSubKey(str);
				m_list1.DeleteItem(nCurSel);
				//m_list1.SetItemText(nCurSel, 1, L"");
				//m_list1.SetItemText(nCurSel, 0, L"");
				break;
			}
		}
		rr.Close();
	}
}
