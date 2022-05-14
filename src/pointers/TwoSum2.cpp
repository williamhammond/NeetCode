#include "TwoSum2.h"

#include <vector>

std::vector<std::size_t> TwoSum2::solve(std::vector<int> numbers, int target) {
    std::size_t i = 0;
    std::size_t j = numbers.size() - 1;
    while (numbers[i] + numbers[j] != target) {
        if (numbers[i] + numbers[j] < target) {
            i++;
        } else {
            j--;
        }
    }
    return {i + 1, j + 1};
}
