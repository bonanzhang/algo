#include <gtest/gtest.h>
#include <queue>
#include <vector>
#include <functional>

TEST(HeapTest, tracksMedian) {
    typedef std::priority_queue<int, std::vector<int>, std::less> min_heap;
    typedef std::priority_queue<int, std::vector<int>, std::greater> max_heap;
    
    min_heap hl;
    max_heap hh;
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
