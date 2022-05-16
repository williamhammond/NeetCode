#include "WaterContainer.h"

#include <algorithm>

std::size_t WaterContainer::solve(std::vector<int> &heights) {
  std::size_t max = 0;
  for (std::size_t i = 0, j = heights.size() - 1; i < j;) {
    max = std::max(max, (j - i) * static_cast<std::size_t>(
                                      std::min(heights[i], heights[j])));
    if (heights[i] < heights[j]) {
      int prev = heights[i];
      while (heights[i] <= prev && i < j) {
        i++;
      }
    } else {
      int prev = heights[j];
      while (heights[j] <= prev && i < j) {
        j--;
      }
    }
  }
  return max;
}
