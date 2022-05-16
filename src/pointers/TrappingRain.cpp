#include "TrappingRain.h"

#include <algorithm>

std::size_t TrappingRain::solve(std::vector<std::size_t>& height) {
  std::size_t left = 0;
  std::size_t right = height.size() - 1;
  std::size_t total_water = 0;
  std::size_t max_left = 0;
  std::size_t max_right = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= max_left) {
        max_left = height[left];
      } else {
        total_water += max_left - height[left];
      }
      left++;
    } else {
      if (height[right] >= max_right) {
        max_right = height[right];
      } else {
        total_water += max_right - height[right];
      }
      right--;
    }
  }
  return total_water;
}
