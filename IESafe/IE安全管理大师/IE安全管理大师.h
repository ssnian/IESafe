
// IE��ȫ�����ʦ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CIE��ȫ�����ʦApp:
// �йش����ʵ�֣������ IE��ȫ�����ʦ.cpp
//

class CIE��ȫ�����ʦApp : public CWinApp
{
public:
	CIE��ȫ�����ʦApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIE��ȫ�����ʦApp theApp;