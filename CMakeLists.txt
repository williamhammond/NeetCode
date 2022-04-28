cmake_minimum_required(VERSION 3.22)
project(NeetCode)

set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# we cannot analyse results without gcov
find_program(GCOV_PATH gcov)
if (NOT GCOV_PATH)
    message(FATAL_ERROR "Code coverage analysis requires gcov!")
endif ()

add_subdirectory(src)

enable_testing()
add_subdirectory(test)


#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
#)
# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)
#
#
#enable_testing()
#add_executable(
#        ContainsDuplicates_test
#        src/arrays/tests/ContainsDuplicates_test.cpp
#)
#target_link_libraries(
#        ContainsDuplicates_test
#        gtest_main
#)
#
#include(GoogleTest)
#gtest_discover_tests(ContainsDuplicates_test)
