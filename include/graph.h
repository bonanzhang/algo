#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <random>
#include <string>
#include <sstream>
#include <climits>
#include <iostream>
#include <cstdlib>
class Vertex {
    private:
        int label_;
    public:
        Vertex();

        Vertex(int label);
        void setLabel(const int label);
        int getLabel() const;

        bool operator==(const Vertex & other) const;
        bool operator<(const Vertex & other) const;
        friend std::ostream& operator<<(std::ostream &os, const Vertex &v);
};
class Graph {
    private:
        std::set<Vertex> visited_;
        std::map<Vertex, std::vector<Vertex> > adj_list_;
    public:
        Graph();
        void addEdge(Vertex u, Vertex v);
        void contract();
        int minCut();
        std::vector<Vertex> BFS();
        std::vector<Vertex> BFS(Vertex start);
        std::vector<Vertex> DFS();
        std::vector<Vertex> DFS(Vertex start);
        friend std::ostream& operator<<(std::ostream &os, const Graph &g);
};
