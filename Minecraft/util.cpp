#include "util.h"

std::wstring Util::convertToWideString(const char* str)
{
    if (str == nullptr) {
        return std::wstring();
    }

    // Get the length of the wide string
    int length = MultiByteToWideChar(CP_ACP, 0, str, -1, nullptr, 0);
    if (length == 0) {
        return std::wstring();
    }

    // Allocate buffer for wide string
    std::wstring wideStr(length, 0);

    // Perform the conversion
    MultiByteToWideChar(CP_ACP, 0, str, -1, &wideStr[0], length);

    return wideStr;
}
