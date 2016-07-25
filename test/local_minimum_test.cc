#include "local_minimum.h"
#include <gtest/gtest.h>
TEST(LocalMinimumTest, HandlesCommonCase) {
    int arr[] = {16, 2, 3,13,
                  5,11,10, 8,
                  9, 7, 6,12,
                  4,14,15, 1};
    long r;
    long c;
    find_local_minimum(arr, 4, &r, &c);
    EXPECT_EQ(r, 0);
    EXPECT_EQ(c, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
