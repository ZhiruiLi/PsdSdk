#include <psd/PsdPch.h>
#include <psd/PsdStringUtil.h>

#include "PsdMemoryUtil.h"

#include <cwchar>
#include <cstdlib>
#include <cstring>

PSD_NAMESPACE_BEGIN

namespace stringUtil
{
	char *ConvertWString(const wchar_t* ws, Allocator* alloc)
	{
		if(ws == nullptr)
		{
			return nullptr;
		}
		char *buffer;
		size_t n = std::wcslen(ws) * 4 + 1;
		buffer = static_cast<char*>(memoryUtil::AllocateArray<char>(alloc,n));
		std::memset(buffer,0,n);
		if(buffer == nullptr)
		{
			return nullptr;
		}
		size_t i;
		wcstombs_s(&i,buffer,n,ws,n);
		return buffer;
	}
}

PSD_NAMESPACE_END
