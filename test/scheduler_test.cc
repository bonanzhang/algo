#include "scheduler.h"
#include <gtest/gtest.h>
TEST(SchedulerTest, HandlesCommonCase) {
    Scheduler s;
    s.addJob(Job(1, 2));
    s.addJob(Job(1, 3));
    s.addJob(Job(1, 1));
    ASSERT_EQ(s.getJob(), Job(1, 1));
    ASSERT_EQ(s.getJob(), Job(1, 2));
    ASSERT_EQ(s.getJob(), Job(1, 3));
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
