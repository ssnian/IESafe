
// IE��ȫ�����ʦDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "page1.h"
#include "page2.h"
#include "page3.h"
#include "page4.h"


// CIE��ȫ�����ʦDlg �Ի���
class CIE��ȫ�����ʦDlg : public CDialogEx
{
// ����
public:
	CIE��ȫ�����ʦDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
