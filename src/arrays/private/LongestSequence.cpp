
#include "arrays/public/LongestSequence.h"
#include<unordered_set>
#include <vector>
#include <algorithm>

int LongestSequence::solve(std::vector<int> &nums) {
    std::unordered_set<int> s(std::begin(nums), std::end(nums));
    int result = 0;
    for (int num: s) {
        if (!s.count(num - 1)) {
            int current_sequence = num + 1;
            while (s.count(current_sequence)) {
                current_sequence += 1;
            }
            result = std::max(result, current_sequence - num);
        }
    }
    return result;
}
