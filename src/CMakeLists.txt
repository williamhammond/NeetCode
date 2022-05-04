set(CMAKE_CXX_STANDARD 17)

add_library(NeetCode arrays/private/ValidAnagram.cpp arrays/public/ValidAnagram.h arrays/private/TwoSum.cpp arrays/public/TwoSum.h arrays/private/GroupAnagrams.cpp arrays/public/GroupAnagrams.h)

target_sources(
        NeetCode
        PRIVATE arrays/private/ContainsDuplicates.cpp
        PUBLIC arrays/public/ContainsDuplicates.h)

target_include_directories(NeetCode PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# we use this to get code coverage flags are only valid with the GNU compiler
# and on Linux
if (CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL
        "Linux")
    target_compile_options(NeetCode PUBLIC "--coverage")
    target_link_options(NeetCode INTERFACE "--coverage")
endif ()
