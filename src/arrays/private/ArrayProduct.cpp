#include "arrays/public/ArrayProduct.h"
#include "iostream"

std::vector<int> ArrayProduct::solve(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> left_product(n);
    left_product[0] = 1;
    for (std::size_t i = 1; i < nums.size(); i++) {
        left_product[i] = left_product[i - 1] * nums[i - 1];
    }

    std::vector<int> right_product(n);
    right_product[n - 1] = 1;
    for (int j = n - 2; j >= 0; j--) {
        right_product[j] = right_product[j + 1] * nums[j + 1];
    }

    std::vector<int> result(n);
    for (int k = 0; k < n; k++) {
        result[k] = left_product[k] * right_product[k];
    }

    return result;
}
