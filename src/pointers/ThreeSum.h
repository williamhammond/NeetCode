
#ifndef NEETCODE_THREESUM_H
#define NEETCODE_THREESUM_H

#include<vector>

class ThreeSum {
public:
    static std::vector<std::vector<int>> solve(std::vector<int> nums);

private:
    std::vector<int> two_sum(std::vector<int> numbers, int target);
};


#endif //NEETCODE_THREESUM_H
