#include "stdafx.h"
#include "Utils.h"

namespace OpenCvWinFormsIpCamera {

  void ToStdString ( String ^s, std::string& os )
	{
		using namespace Runtime::InteropServices;
		const char *chars = 
			(const char *)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void *)chars));
	}

	void ToStdString ( String ^s, std::wstring& os )
	{
		using namespace Runtime::InteropServices;
		const wchar_t *chars = 
			(const wchar_t *)(Marshal::StringToHGlobalUni(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void *)chars));
	}
}
