#pragma once
#include <string>
#include <codecvt>
#ifdef _WIN32
#define NOMINMAX
#include "Windows.h"
inline void warn(const std::wstring &msg)
{
	MessageBoxW(NULL, msg.c_str(), L"Warn", MB_ICONINFORMATION);
}
inline void warn(const std::string &msg)
{
	MessageBoxW(NULL, std::wstring(msg.cbegin(), msg.cend()).c_str(), L"Warn", MB_ICONINFORMATION);
}
#else
inline void warn(const std::wstring &msg)
{
	//wyœwietlanie dla innych platform
}
inline void warn(const std::string &msg)
{
	//wyœwietlanie dla innych platform
}
#endif
class w_err : public std::runtime_error
{
public:
	w_err(const std::wstring &msg) : runtime_error("Critical Error!"), msg(msg) {}
	const std::wstring msg;
};