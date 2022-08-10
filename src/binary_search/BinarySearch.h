#ifndef NEETCODE_SRC_BINARY_SEARCH_BINARYSEARCH_H_
#define NEETCODE_SRC_BINARY_SEARCH_BINARYSEARCH_H_

#include "vector"

class BinarySearch {
 public:
  static int search(std::vector<int>& nums, int target);
  static bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);
  static int searchRotated(std::vector<int>& nums, int target);
};

#endif  // NEETCODE_SRC_BINARY_SEARCH_BINARYSEARCH_H_
