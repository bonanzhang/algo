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
        std::string label_;
    public:
        Vertex();

        Vertex(std::string label);
        void setLabel(const std::string label);
        std::string getLabel() const;

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
        void BFS();
        void BFS(Vertex start);
        void DFS();
        void DFS(Vertex start);
        friend std::ostream& operator<<(std::ostream &os, const Graph &g);
};
