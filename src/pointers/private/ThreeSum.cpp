#include "pointers/public/ThreeSum.h"

#include <algorithm>
#include <vector>

std::vector<std::vector<int>> ThreeSum::solve(std::vector<int> nums) {
    if (nums.size() <= 2) {
        return {};
    }
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result = {};
    for (std::size_t i = 0; i < nums.size(); i++) {
        std::size_t j = i + 1;
        std::size_t k = nums.size() - 1;
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0) {
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (nums[j] == nums[j - 1] && j < k) j++;
            }
        }
    }
    return result;
}
