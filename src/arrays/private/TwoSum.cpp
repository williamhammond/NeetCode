#include "arrays/public/TwoSum.h"

vector<std::size_t> TwoSum::solve(vector<int> &nums, int target) {
    std::unordered_map<int, std::size_t> indexes;
    for (std::size_t i = 0; i < nums.size(); i++) {
        auto it = indexes.find(target - nums[i]);
        if (it != indexes.end()) {
            return vector<std::size_t>{it->second, i};
        }

        indexes[nums[i]] = i;
    }
    return {};
}
