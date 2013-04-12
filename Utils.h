#pragma once

#include <string>

namespace OpenCvWinFormsIpCamera {

  using namespace System;

	void ToStdString ( String ^s, std::string& os );
	void ToStdString ( String ^s, std::wstring& os );
}
