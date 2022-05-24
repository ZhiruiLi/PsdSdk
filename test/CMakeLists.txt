find_package(Catch2 QUIET)
if(TARGET Catch2::Catch2)
    # message("++ Target Catch2 has been installed previously.")
else(TARGET Catch2::Catch2)
    # message("++ Target Catch2 not found, start downloading...")
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.8
    )
    FetchContent_MakeAvailable(Catch2)
endif(TARGET Catch2::Catch2)

add_executable(PsdTest
    PsdTest.cpp
)

target_compile_features(PsdTest PRIVATE cxx_auto_type)
target_compile_options(PsdTest PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/WX /W4 /utf-8 /MD>
)

target_link_libraries(PsdTest Catch2::Catch2 Psd::Psd)

add_test(NAME psdtest COMMAND PsdTest)
