add_library(NeetCode)

target_sources(NeetCode
        PRIVATE
        arrays/private/ContainsDuplicates.cpp
        PUBLIC
        arrays/public/ContainsDuplicates.h
        )

target_include_directories(NeetCode
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if (CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(NeetCode
            PUBLIC
            "--coverage"
            )
    target_link_options(NeetCode
            INTERFACE
            "--coverage"
            )
endif ()