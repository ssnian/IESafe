
// IE安全管理大师Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "page1.h"
#include "page2.h"
#include "page3.h"
#include "page4.h"


// CIE安全管理大师Dlg 对话框
class CIE安全管理大师Dlg : public CDialogEx
{
// 构造
public:
	CIE安全管理大师Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CPage1 m_page1;
	CPage2 m_page2;
	CPage3 m_page3;
	CPage4 m_page4;
	int m_CurSelTab;
	CDialog* pDialog[4];  
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
