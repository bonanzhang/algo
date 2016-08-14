#include "graph.h"
#include "weighted_graph.h"
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
    Graph g;
    g.addEdge(Vertex(1), Vertex(2));
    g.addEdge(Vertex(2), Vertex(3));
    g.addEdge(Vertex(3), Vertex(1));
    g.addEdge(Vertex(3), Vertex(4));
    g.addEdge(Vertex(5), Vertex(4));
    g.addEdge(Vertex(6), Vertex(4));
    g.addEdge(Vertex(8), Vertex(6));
    g.addEdge(Vertex(6), Vertex(7));
    g.addEdge(Vertex(7), Vertex(8));
    g.addEdge(Vertex(4), Vertex(3));
    g.addEdge(Vertex(4), Vertex(6));

    std::vector<std::vector<Vertex> > res= g.findStronglyConnectedComponents();
    int expected[] = {7,1};
    ASSERT_EQ(sizeof(expected)/sizeof(expected[0]), res.size());
    for (int i = 0; i < res.size(); i++) {
        EXPECT_EQ(res[i].size(), expected[i]);
    }
    
}
TEST(WeightedGraphTest, FindsShortestPaths) {
    WeightedGraph wg;
    wg.addEdge(Vertex(1), Vertex(2), 7);
    wg.addEdge(Vertex(1), Vertex(3), 9);
    wg.addEdge(Vertex(1), Vertex(6), 14);

    wg.addEdge(Vertex(2), Vertex(1), 7);
    wg.addEdge(Vertex(2), Vertex(3), 10);
    wg.addEdge(Vertex(2), Vertex(4), 15);

    wg.addEdge(Vertex(3), Vertex(1), 9);
    wg.addEdge(Vertex(3), Vertex(2), 10);
    wg.addEdge(Vertex(3), Vertex(4), 11);
    wg.addEdge(Vertex(3), Vertex(6), 2);

    wg.addEdge(Vertex(4), Vertex(2), 15);
    wg.addEdge(Vertex(4), Vertex(3), 11);
    wg.addEdge(Vertex(4), Vertex(5), 6);

    wg.addEdge(Vertex(5), Vertex(4), 6);
    wg.addEdge(Vertex(5), Vertex(6), 9);

    wg.addEdge(Vertex(6), Vertex(1), 14);
    wg.addEdge(Vertex(6), Vertex(3), 2);
    wg.addEdge(Vertex(6), Vertex(5), 9);
//    std::cout << wg << std::endl;
    int expected[] = {0,7,9,20,20,11};
    std::map<Vertex, int> dist = wg.computeShortestPaths(Vertex(1));
    for (int i = 1; i <= 6; i++) {
        EXPECT_EQ(dist[Vertex(i)], expected[i-1]);
    }
//    for (std::map<Vertex, int>::const_iterator it = dist.begin(); it != dist.end(); ++it) {
//        std::cout << it->first << "," << it->second << std::endl;
//    }
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
