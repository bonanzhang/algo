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
    Vertex *v1 = new Vertex(1);
    g.addVertex(v1);
    Vertex *v2 = new Vertex(2);
    g.addVertex(v2);
    Edge *e1 = new Edge(v1, v2);
    g.addEdge(e1);
    Vertex *v3 = new Vertex(3);
    g.addVertex(v3);
    Edge *e2 = new Edge(v1, v3);
    g.addEdge(e2);
    std::cout << g;
    complete = 1;
    EXPECT_EQ(complete, 1);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
