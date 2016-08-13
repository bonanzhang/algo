#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <random>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>
#include <iostream>
#include <cstdlib>
#include "vertex.h"
class Graph {
    private:
        std::set<Vertex> visited_;
        std::map<Vertex, std::vector<Vertex> > adj_list_;
        std::map<Vertex, std::vector<Vertex> > rev_graph_;
        std::vector<Vertex> finished_;

        void contract();
        std::vector<std::vector<Vertex> > DFS(std::vector<Vertex> order);
        std::vector<Vertex> BFS(Vertex start);
        std::vector<Vertex> DFS(Vertex start);
        std::vector<Vertex> DFS_rev();
        std::vector<Vertex> DFS_rev(Vertex start);
    public:
        Graph();
        void addEdge(Vertex u, Vertex v);
        int minCut();
        std::vector<Vertex> BFS();
        std::vector<Vertex> DFS();
        std::vector<std::vector<Vertex> > findStronglyConnectedComponents();
        friend std::ostream& operator<<(std::ostream &os, const Graph &g);
};
