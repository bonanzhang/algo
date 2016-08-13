#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
#include <unordered_set>
TEST(HashTest, Handles2sum) {
    std::ifstream ifs("/home/bonan/algo/resources/2sum.txt");
    ASSERT_TRUE(ifs.is_open());
    std::unordered_set<long> seen;
    long num;
    while (ifs >> num) {
        seen.insert(num);
    }
    ASSERT_TRUE(seen.size() > 0);
    int counter = 0;
    for (int T = -10000; T <= 10000; T++) {
        for (std::unordered_set<long>::const_iterator it = seen.begin(); it != seen.end(); ++it) {
            if (seen.find(T-(*it)) != seen.end() && ((*it) != (T-(*it)))) {
                counter++;
                break;
            }
        }
    }
    std::cout << counter << std::endl;
}
int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
