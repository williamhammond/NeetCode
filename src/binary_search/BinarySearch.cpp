#include "BinarySearch.h"

int BinarySearch::search(std::vector<int>& nums, int target) {
  if (nums.empty()) {
    return -1;
  }

  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] > target)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}
