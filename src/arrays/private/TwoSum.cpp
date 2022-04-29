#include "arrays/public/TwoSum.h"

vector<int> TwoSum::solve(vector<int> &nums, int target) {
    std::unordered_map<int, int> indexes;
    for (int i = 0; i < nums.size(); i++) {
        auto it = indexes.find(target - nums[i]);
        if (it != indexes.end()) {
            return vector<int>{it->second, i};
        }

        indexes[nums[i]] = i;
    }
    return {};
}
