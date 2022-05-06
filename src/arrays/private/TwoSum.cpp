#include "arrays/public/TwoSum.h"

vector<int> TwoSum::solve(vector<int> &nums, int target) {
    std::unordered_map<int, int> indexes;
    for (std::size_t i = 0; i < nums.size(); i++) {
        auto it = indexes.find(target - nums[i]);
        if (it != indexes.end()) {
            return vector<int>{it->second, (int) i};
        }

        indexes[nums[i]] = i;
    }
    return {};
}
