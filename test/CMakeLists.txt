set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        gtest
        QUIET
        URL https://github.com/google/googletest/archive/release-1.11.0.tar.gz)
# configure build of googletest
set(gtest_force_shared_crt
        ON
        CACHE BOOL "" FORCE)
set(BUILD_GMOCK
        OFF
        CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(gtest)

add_executable(unit_tests arrays/ContainsDuplicates_test.cpp arrays/ValidAnagram_test.cpp arrays/TwoSum_test.cpp arrays/GroupAnagrams_test.cpp arrays/TopKFrequentElements_test.cpp arrays/ArrayProduct_test.cpp arrays/Sudoku_test.cpp)

target_link_libraries(unit_tests PRIVATE NeetCode gtest_main)

if (MSVC)
    target_compile_options(unit_tests PRIVATE /W4 /WX)
else ()
    target_compile_options(unit_tests PRIVATE -Wall -Wextra -pedantic -Werror -Wshadow -Wdouble-promotion -Wundef -Wconversion)
endif ()

# automatic discovery of unit tests
include(GoogleTest)
gtest_discover_tests(
        unit_tests
        PROPERTIES LABELS "unit" DISCOVERY_TIMEOUT # how long to wait (in seconds)
        # before crashing
        240)
