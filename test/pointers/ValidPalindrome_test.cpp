#include <gtest/gtest.h>
#include "pointers/ValidPalindrome.h"
#include <string>

TEST(ValidPalindrome, solves) {
    std::string input = "A man, a plan, a canal: Panama";
    bool result = ValidPalindrome::solve(input);
    EXPECT_EQ(true, result);

    input = "race a car";
    result = ValidPalindrome::solve(input);
    EXPECT_EQ(false, result);

    input = " ";
    result = ValidPalindrome::solve(input);
    EXPECT_EQ(true, result);

    input = "a";
    result = ValidPalindrome::solve(input);
    EXPECT_EQ(true, result);

    input = "aa";
    result = ValidPalindrome::solve(input);
    EXPECT_EQ(true, result);
}
