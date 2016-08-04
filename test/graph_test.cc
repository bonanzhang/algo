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
    g.addEdge(v1, v1_2);
    Vertex v1_3("3");
    g.addEdge(v1, v1_3);

    Vertex v2("2");
    Vertex v2_1("1");
    g.addEdge(v2, v2_1);

    Vertex v3("3");
    Vertex v3_1("1");
    g.addEdge(v3, v3_1);
    std::cout << g << std::endl;

    complete = 1;
    EXPECT_EQ(complete, 1);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
