#include "graph.h"
#include <gtest/gtest.h>
TEST(GraphTraversalTest, HandlesBFS) {
    Graph g;
    g.addEdge(Vertex(1), Vertex(2));
    g.addEdge(Vertex(1), Vertex(5));
    g.addEdge(Vertex(1), Vertex(8));
    g.addEdge(Vertex(2), Vertex(3));
    g.addEdge(Vertex(3), Vertex(4));
    g.addEdge(Vertex(4), Vertex(2));
    g.addEdge(Vertex(5), Vertex(6));
    g.addEdge(Vertex(6), Vertex(3));
    g.addEdge(Vertex(6), Vertex(7));
    g.addEdge(Vertex(6), Vertex(8));
     
    std::vector<Vertex> res = g.BFS();
    int expected[] = {1,2,5,8,3,6,4,7};
    ASSERT_EQ(sizeof(expected)/sizeof(expected[0]), res.size());
    for (int i = 0; i < res.size(); i++) {
        EXPECT_EQ(res[i].getLabel(), expected[i]);
    }
}
TEST(GraphTraversalTest, HandlesDFS) {
    Graph g;
    g.addEdge(Vertex(1), Vertex(2));
    g.addEdge(Vertex(1), Vertex(5));
    g.addEdge(Vertex(1), Vertex(8));
    g.addEdge(Vertex(2), Vertex(3));
    g.addEdge(Vertex(3), Vertex(4));
    g.addEdge(Vertex(4), Vertex(2));
    g.addEdge(Vertex(5), Vertex(6));
    g.addEdge(Vertex(6), Vertex(3));
    g.addEdge(Vertex(6), Vertex(7));
    g.addEdge(Vertex(6), Vertex(8));
     
    std::vector<Vertex> res = g.DFS();
    int expected[] = {1,8,5,6,7,3,4,2};
    ASSERT_EQ(sizeof(expected)/sizeof(expected[0]), res.size());
    for (int i = 0; i < res.size(); i++) {
        EXPECT_EQ(res[i].getLabel(), expected[i]);
    }
}
TEST(GraphComponentsTest, FindsSCC) {
    Graph G;
    Graph G_rev;
    G.addEdge(Vertex(1), Vertex(2));
    G.addEdge(Vertex(2), Vertex(3));
    G.addEdge(Vertex(3), Vertex(1));
    G.addEdge(Vertex(3), Vertex(4));
    G.addEdge(Vertex(5), Vertex(4));
    G.addEdge(Vertex(6), Vertex(4));
    G.addEdge(Vertex(8), Vertex(6));
    G.addEdge(Vertex(6), Vertex(7));
    G.addEdge(Vertex(7), Vertex(8));
    G.addEdge(Vertex(4), Vertex(3));
    G.addEdge(Vertex(4), Vertex(6));

    G_rev.addEdge(Vertex(2), Vertex(1));
    G_rev.addEdge(Vertex(3), Vertex(2));
    G_rev.addEdge(Vertex(1), Vertex(3));
    G_rev.addEdge(Vertex(4), Vertex(3));
    G_rev.addEdge(Vertex(4), Vertex(5));
    G_rev.addEdge(Vertex(4), Vertex(6));
    G_rev.addEdge(Vertex(6), Vertex(8));
    G_rev.addEdge(Vertex(7), Vertex(6));
    G_rev.addEdge(Vertex(8), Vertex(7));
    G_rev.addEdge(Vertex(3), Vertex(4));
    G_rev.addEdge(Vertex(6), Vertex(4));
    std::vector<Vertex> order = G_rev.DFS();
    std::vector<std::vector<Vertex> > res= G.SCC_second_pass(order);
    int expected[] = {7,1};
    ASSERT_EQ(sizeof(expected)/sizeof(expected[0]), res.size());
    for (int i = 0; i < res.size(); i++) {
        EXPECT_EQ(res[i].size(), expected[i]);
    }
    
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
