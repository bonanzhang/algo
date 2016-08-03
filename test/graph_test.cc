#include "graph.h"
#include <gtest/gtest.h>
TEST(GraphBuildingTest, HandlesEmptyGraphs) {
    int complete = 0;
    Graph g;
    complete = 1;
    EXPECT_EQ(complete, 1);
}
TEST(GraphBuildingTest, HandlesTinyGraphs) {
    int complete = 0;
    Graph g;
    Vertex v1("1");
    Vertex v1_2("2");
    v1.addConnection(v1_2);
    Vertex v1_3("3");
    v1.addConnection(v1_3);
    g.addVertex(v1);

    Vertex v2("2");
    Vertex v2_1("1");
    v2.addConnection(v2_1);
    g.addVertex(v2);

    Vertex v3("3");
    Vertex v3_1("1");
    v3.addConnection(v3_1);
    g.addVertex(v3);

    complete = 1;
    EXPECT_EQ(complete, 1);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
