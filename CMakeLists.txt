cmake_minimum_required(VERSION 3.13...3.19 FATAL_ERROR)
project(PsdSdk VERSION 1.0.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)

option(PSD_BUILD_TESTS "Build test program" ON)
option(PSD_BUILD_EXAMPLES "Build example program" ON)
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

# ----------------------------------------------------------------
# create and setup compile target
# ----------------------------------------------------------------

include (GenerateExportHeader)
if(WIN32)
    set(CMAKE_SUPPORT_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif(WIN32)

add_library(psd
    src/PsdAllocator.cpp
    src/PsdBitUtil.h
    src/PsdBlendMode.cpp
    src/PsdColorMode.cpp
    src/PsdDecompressRle.cpp
    src/PsdEndianConversion.h
    src/PsdExport.cpp
    src/PsdFile.cpp
    src/PsdFixedSizeString.cpp
    src/PsdInterleave.cpp
    src/Psdispod.h
    src/PsdLayerCanvasCopy.cpp
    src/PsdMallocAllocator.cpp
    src/PsdMemoryUtil.h
    src/Psdminiz.cpp
    src/Psdminiz.h
    src/PsdParseColorModeDataSection.cpp
    src/PsdParseDocument.cpp
    src/PsdParseImageDataSection.cpp
    src/PsdParseImageResourcesSection.cpp
    src/PsdParseLayerMaskSection.cpp
    src/PsdPch.cpp
    src/PsdStringUtil.cpp
    src/PsdSyncFileReader.cpp
    src/PsdSyncFileUtil.h
    src/PsdSyncFileWriter.cpp
    src/PsdUnionCast.h
    $<$<PLATFORM_ID:Windows>:src/PsdNativeFile_Windows.cpp>
    $<$<PLATFORM_ID:Linux>:src/PsdNativeFile_Linux.cpp>
    $<$<PLATFORM_ID:Darwin>:src/PsdNativeFile_Darwin.mm>
)

GENERATE_EXPORT_HEADER (psd
    BASE_NAME psd
    EXPORT_MACRO_NAME PSD_API
    EXPORT_FILE_NAME include/psd/PsdApi.h
)

# add alias
add_library(Psd::Psd ALIAS psd)

# setup props
target_include_directories(psd
    PUBLIC $<INSTALL_INTERFACE:include> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(psd PRIVATE cxx_auto_type)
target_compile_options(psd PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/WX /W4 /utf-8 /MD>
)

set_target_properties(psd PROPERTIES DEBUG_POSTFIX "d")

# ----------------------------------------------------------------
# install
# ----------------------------------------------------------------

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/Psd)

install(TARGETS psd
    EXPORT psd-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set_target_properties(psd PROPERTIES EXPORT_NAME Psd)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT psd-targets
    FILE PsdTargets.cmake
    NAMESPACE Psd::
    DESTINATION ${INSTALL_CONFIGDIR}
)

# create ConfigVersion.cmake
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/PsdConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/PsdConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/PsdConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

# create config
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/PsdConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/PsdConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

# ----------------------------------------------------------------
# export symbols
# ----------------------------------------------------------------

export(EXPORT psd-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/PsdTargets.cmake
    NAMESPACE Psd::)

export(PACKAGE Psd)

# ----------------------------------------------------------------
# add tests
# ----------------------------------------------------------------

if(PSD_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif(PSD_BUILD_TESTS)

# ----------------------------------------------------------------
# add examples
# ----------------------------------------------------------------

if(PSD_BUILD_EXAMPLES)
    add_subdirectory(examples/PsdSample)
endif(PSD_BUILD_EXAMPLES)
