#include "arrays/ValidAnagram.h"

#include <gtest/gtest.h>

TEST(ValidAnagrams, IsValid) {
  bool result = ValidAnagram::solve("anagram", "nagaram");
  EXPECT_EQ(result, true) << "Didn't detect valid anagram ";

  result = ValidAnagram::solve("aaaa", "aaaa");
  EXPECT_EQ(result, true) << "Didn't detect valid anagram ";

  result = ValidAnagram::solve("", "");
  EXPECT_EQ(result, true) << "Didn't detect valid anagram ";

  result = ValidAnagram::solve("a", "a");
  EXPECT_EQ(result, true) << "Didn't detect valid anagram ";
}

TEST(ValidAnagrams, IsInvalid) {
  bool result = ValidAnagram::solve("cat", "rat");
  EXPECT_EQ(result, false) << "Incorrectly detected anagram";

  result = ValidAnagram::solve("a", "aa");
  EXPECT_EQ(result, false) << "Incorrectly detected anagram";

  result = ValidAnagram::solve("aa", "a");
  EXPECT_EQ(result, false) << "Incorrectly detected anagram";
}
