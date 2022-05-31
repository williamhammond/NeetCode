set(CMAKE_CXX_STANDARD 17)

add_library(NeetCode arrays/ValidAnagram.cpp arrays/ValidAnagram.h arrays/TwoSum.cpp arrays/TwoSum.h arrays/GroupAnagrams.cpp arrays/GroupAnagrams.h arrays/TopKFrequentElements.cpp arrays/TopKFrequentElements.h arrays/ArrayProduct.cpp arrays/ArrayProduct.h arrays/Sudoku.cpp arrays/Sudoku.h arrays/Codec.cpp arrays/Codec.h arrays/LongestSequence.cpp arrays/LongestSequence.h pointers/ValidPalindrome.cpp pointers/ValidPalindrome.h pointers/TwoSum2.cpp pointers/TwoSum2.h pointers/ThreeSum.cpp pointers/ThreeSum.h pointers/WaterContainer.cpp pointers/WaterContainer.h pointers/TrappingRain.cpp pointers/TrappingRain.h sliding_window/SlidingWindow.cpp sliding_window/SlidingWindow.h stack/Stack.cpp stack/Stack.h)

target_sources(
        NeetCode
        PRIVATE arrays/ContainsDuplicates.cpp
        PUBLIC arrays/ContainsDuplicates.h)

target_include_directories(NeetCode PUBLIC ${CMAKE_CURRENT_LIST_DIR})

if (MSVC)
    target_compile_options(NeetCode PRIVATE /W4 /WX)
else ()
    target_compile_options(NeetCode PRIVATE -Wall -Wextra -pedantic -Wshadow -Wdouble-promotion -Wundef -Wconversion)
endif ()
