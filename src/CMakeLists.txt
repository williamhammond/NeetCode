set(CMAKE_CXX_STANDARD 17)

add_library(NeetCode arrays/private/ValidAnagram.cpp arrays/public/ValidAnagram.h arrays/private/TwoSum.cpp arrays/public/TwoSum.h arrays/private/GroupAnagrams.cpp arrays/public/GroupAnagrams.h arrays/private/TopKFrequentElements.cpp arrays/public/TopKFrequentElements.h arrays/private/ArrayProduct.cpp arrays/public/ArrayProduct.h arrays/private/Sudoku.cpp arrays/public/Sudoku.h arrays/private/Codec.cpp arrays/public/Codec.h arrays/private/LongestSequence.cpp arrays/public/LongestSequence.h pointers/private/ValidPalindrome.cpp pointers/public/ValidPalindrome.h pointers/private/TwoSum2.cpp pointers/public/TwoSum2.h)

target_sources(
        NeetCode
        PRIVATE arrays/private/ContainsDuplicates.cpp
        PUBLIC arrays/public/ContainsDuplicates.h)

target_include_directories(NeetCode PUBLIC ${CMAKE_CURRENT_LIST_DIR})

if (MSVC)
    target_compile_options(NeetCode PRIVATE /W4 /WX)
else ()
    target_compile_options(NeetCode PRIVATE -Wall -Wextra -pedantic -Werror -Wshadow -Wdouble-promotion -Wundef -Wconversion)
endif ()
