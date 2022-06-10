#pragma once

#include "../../EterLib/Srcs/StdAfx.h"
#include "../../EterGrnLib/Srcs/StdAfx.h"

//#include <crtdbg.h>
#ifdef _DEBUG
	#undef _DEBUG
	#include <Python_2.7.18/include/python.h>
	#define _DEBUG
#else
	#include <Python_2.7.18/include/python.h>
#endif
#include <Python_2.7.18/include/node.h>
#include <Python_2.7.18/include/grammar.h>
#include <Python_2.7.18/include/token.h>
#include <Python_2.7.18/include/parsetok.h>
#include <Python_2.7.18/include/errcode.h>
#include <Python_2.7.18/include/compile.h>
#include <Python_2.7.18/include/symtable.h>
#include <Python_2.7.18/include/eval.h>
#include <Python_2.7.18/include/marshal.h>

#include "PythonUtils.h"
#include "PythonLauncher.h"
#include "PythonMarshal.h"
#include "Resource.h"

void initdbg();

// PYTHON_EXCEPTION_SENDER
class IPythonExceptionSender
{
	public:
		void Clear()
		{
			m_strExceptionString = "";
		}

		void RegisterExceptionString(const char * c_szString)
		{
			m_strExceptionString += c_szString;
		}

		virtual void Send() = 0;

	protected:
		std::string m_strExceptionString;
};

extern IPythonExceptionSender * g_pkExceptionSender;

void SetExceptionSender(IPythonExceptionSender * pkExceptionSender);
// END_OF_PYTHON_EXCEPTION_SENDER
