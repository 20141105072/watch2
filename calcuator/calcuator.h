
// calcuator.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CcalcuatorApp:
// �йش����ʵ�֣������ calcuator.cpp
//

class CcalcuatorApp : public CWinApp
{
public:
	CcalcuatorApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CcalcuatorApp theApp;