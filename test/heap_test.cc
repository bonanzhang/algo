#include <gtest/gtest.h>
#include <queue>
#include <vector>
#include <functional>
TEST(HeapTest, tracksMedian) {
    typedef std::priority_queue<int, std::vector<int>, std::less<int>    > max_heap;
    typedef std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
    
    max_heap hl;
    min_heap hh;

    std::vector<int> input {4,5,3,2,1};
    std::vector<int> expected {4,5,4,3,3};
    std::vector<int> res;
    //while not done
    for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it) {
        //get next input i
        int i = *it;
        //insert
        if (hl.empty()) {
            hl.push(i);
        } else if (hh.empty()) {
            hh.push(i);
        } else {
            int max = hl.top();
            int min = hh.top();
            if (i < max) {
                hl.push(i);
            } else if (i > min) {
                hh.push(i);
            } else {
                hl.push(i);
            }
        }
        //fix
        if ((hl.size() - hh.size()) > 1) {
            int min = hh.top();
            hh.pop();
            hl.push(min);
        }
        if ((hh.size() - hl.size()) > 1) {
            int max = hl.top();
            hl.pop();
            hh.push(max);
        }
        //result
        if (hl.size() > hh.size()) {
            res.push_back(hl.top());
        } else if (hh.size() > hl.size()) {
            res.push_back(hh.top());
        } else {
            res.push_back(hl.top());
        }
    }
    ASSERT_EQ(res.size(), expected.size());
    for (int i = 0; i < expected.size(); i++) {
        EXPECT_EQ(expected[i], res[i]);
    }
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
