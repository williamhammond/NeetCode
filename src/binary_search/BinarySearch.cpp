#include "BinarySearch.h"

int BinarySearch::search(std::vector<int>& nums, int target) {
  if (nums.empty()) {
    return -1;
  }

  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    // Prevents issues here
    // https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
    int mid = (left + right) >> 1;
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}
bool BinarySearch::searchMatrix(std::vector<std::vector<int>>& matrix,
                                int target) {
  for (auto row : matrix) {
    if (row[0] > target) {
      return false;
    }
    if (row[row.size() - 1] >= target) {
      return search(row, target) != -1;
    }
  }
  return false;
}

int BinarySearch::searchRotated(std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  while (left < right) {
    // Prevents issues here
    // https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
    int mid = (left + right) >> 1;
    if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  int rotation = left;
  left = 0;
  right = nums.size() - 1;
  while (left <= right) {
    int mid = (left + right) >> 1;
    int real_mid = (mid + rotation) % nums.size();

    if (nums[real_mid] == target) {
      return real_mid;
    }

    if (nums[real_mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}
