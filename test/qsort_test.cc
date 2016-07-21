#include "qsort.h"
#include <gtest/gtest.h>
TEST(QuickSortTest, HandlesCommonCase) {
    int arr[] = {1,3,5,2,4,6};
    long i;
    long sorted;
    long sz = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, sz);
    sorted = 1;
    for (i = 1; i < sz; i++){
        if (arr[i-1] > arr[i]) {
            sorted = 0;
            break;
        }
    }
    EXPECT_EQ(sorted, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
