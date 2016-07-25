#include "local_minimum.h"
#include <gtest/gtest.h>
TEST(LocalMinimumTest, HandlesEdgeCase) {
    long r,c;
    int arr[] = {5,1,3,
                 2,4,6,
                 0,9,7};
    find_local_minimum(arr, 3, &r, &c);
    EXPECT_EQ(r, 0);
    EXPECT_EQ(c, 1);
}
TEST(LocalMinimumTest, HandlesCornerCase) {
    long r,c;
    int arr[] = {0,1,2,
                 3,4,5,
                 6,7,8};
    find_local_minimum(arr, 3, &r, &c);
    EXPECT_EQ(r, 0);
    EXPECT_EQ(c, 0);
}
TEST(LocalMinimumTest, HandlesCommonCase) {
    long r,c;
    int arr[] = {5,2,6,
                 1,0,3,
                 7,4,8};
    find_local_minimum(arr, 3, &r, &c);
    EXPECT_EQ(r, 1);
    EXPECT_EQ(c, 1);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
