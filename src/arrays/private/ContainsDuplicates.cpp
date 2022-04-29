#include "../public/ContainsDuplicates.h"
#include <map>


bool ContainsDuplicates::solve(vector<int> &nums) {
    std::map<int, int> counts;
    for (auto num: nums) {
        if (counts.count(num)) {
            return true;
        } else {
            counts.emplace(num, 1);
        }
    }
    return false;
}
