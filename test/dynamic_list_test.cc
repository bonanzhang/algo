#include "dynamic_list.h"
#include <gtest/gtest.h>
TEST(DynamicListTest, HandlesInsertions) {
    dynamic_int_list l0 = {.list = NULL, .size = 0, .capacity = 0};
    init_dynamic_int_list(&l0, 10);
    for (int i = 0; i < 100; i++) {
        push_back_to_dynamic_int_list(&l0, &i);
    }
    EXPECT_EQ(l0.list[99], 99);
    free_dynamic_int_list(&l0);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
