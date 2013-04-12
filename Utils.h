#pragma once

#include <string>

namespace WinformsIPcamera2 {

  using namespace System;

	void ToStdString ( String ^s, std::string& os );
	void ToStdString ( String ^s, std::wstring& os );
}
