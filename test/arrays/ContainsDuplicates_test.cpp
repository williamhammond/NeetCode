#include <gtest/gtest.h>
#include "../../src/arrays/public/ContainsDuplicates.h"

TEST(ContainsDuplicates, NoDuplicateSimple) {
    std::vector<int> input = {1, 2, 3, 4};
    bool result = ContainsDuplicates::solve(input);
    EXPECT_EQ(result, false) << "Falsely found a duplicate";
}

