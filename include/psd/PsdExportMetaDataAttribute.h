// Copyright 2011-2020, Molecular Matters GmbH <office@molecular-matters.com>
// See LICENSE.txt for licensing details (2-clause BSD License: https://opensource.org/licenses/BSD-2-Clause)

#pragma once

#include <psd/PsdPch.h>

PSD_NAMESPACE_BEGIN

/// \ingroup Types
/// \class ExportMetaDataAttribute
/// \brief A struct representing a meta data attribute as exported to the image resources section.
struct PSD_API ExportMetaDataAttribute
{
	char* name;
	char* value;
};

PSD_NAMESPACE_END
