add_executable(PsdSample
    PsdSample.cpp
    PsdTgaExporter.cpp
    PsdTgaExporter.h
)

target_compile_features(PsdSample PRIVATE cxx_auto_type)
target_compile_options(PsdSample PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/WX /W4 /utf-8 /MD>
)

target_link_libraries(PsdSample Psd::Psd)
