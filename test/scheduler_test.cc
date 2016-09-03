#include "scheduler.h"
#include <gtest/gtest.h>
TEST(SchedulerTest, HandlesCommonCase) {
    Scheduler s;
    s.addJob(Job(1.0f, 2.0f));
    s.addJob(Job(1.0f, 3.0f));
    s.addJob(Job(1.0f, 1.0f));
    ASSERT_EQ(s.getJob(), Job(1.0f, 1.0f));
    ASSERT_EQ(s.getJob(), Job(1.0f, 2.0f));
    ASSERT_EQ(s.getJob(), Job(1.0f, 3.0f));
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
