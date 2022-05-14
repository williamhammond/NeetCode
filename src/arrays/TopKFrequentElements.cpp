#include "TopKFrequentElements.h"

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

std::vector<int> TopKFrequentElements::solve(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> frequencies;
    for (auto num: nums) {
        if (!frequencies.count(num)) {
            frequencies.emplace(num, 1);
        } else {
            frequencies.find(num)->second++;
        }
    }
    auto compare = [](std::pair<int, int> lhs, std::pair<int, int> rhs) {
        return (lhs.second < rhs.second) || (!(lhs.second > rhs.second) && lhs.second < rhs.second);
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> queue(compare);
    for (auto pair: frequencies) {
        queue.push(pair);
    }
    std::vector<int> result;
    for (int i = 0; i < k; i++) {
        int value = queue.top().first;
        result.push_back(value);
        queue.pop();
    }
    return result;
}
