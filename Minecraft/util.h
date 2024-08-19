#ifndef UTIL_CLASS_H
#define UTIL_CLASS_H

#include <Windows.h>
#include <iostream>

class Util
{
public:
	static std::wstring convertToWideString(const char* str);
};

#endif // !UTIL_CLASS_H
