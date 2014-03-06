#pragma once
class CDirDialog
{
public:
	void Browse();
	CDirDialog(void);
	~CDirDialog(void);
public:
	CString m_strSelDir;
	CString m_strInitDir;
};

