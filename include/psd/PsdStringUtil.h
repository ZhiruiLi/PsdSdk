#pragma once

#include <psd/PsdPch.h>
#include <psd/PsdAllocator.h>

PSD_NAMESPACE_BEGIN

namespace stringUtil
{

	///
	/// \brief Convert wchar_t * to char *
	/// 
	/// \param ws The wide string
	/// \param alloc The mem allocator
	/// \return char* nullptr on error
	///
	PSD_API char *ConvertWString(const wchar_t* ws, Allocator* alloc);

}

PSD_NAMESPACE_END
