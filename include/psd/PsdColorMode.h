// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include <psd/PsdPch.h>

PSD_NAMESPACE_BEGIN

/// \ingroup Types
/// \namespace colorMode
/// \brief A namespace holding all color modes known by Photoshop.
namespace colorMode
{
	enum PSD_API Enum
	{
		BITMAP = 0,
		GRAYSCALE = 1,
		INDEXED = 2,
		RGB = 3,
		CMYK = 4,
		MULTICHANNEL = 7,
		DUOTONE = 8,
		LAB = 9
	};

	/// Converts any of the \ref colorMode::Enum values into a string literal.
	PSD_API const char* ToString(unsigned int value);
}

PSD_NAMESPACE_END
