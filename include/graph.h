#include <vector>
#include <set>
#include <map>
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
        void setLabel(std::string label);
        std::string getLabel() const;

        bool operator==(const Vertex & other) const;
        bool operator<(const Vertex & other) const;
        friend std::ostream& operator<<(std::ostream &os, const Vertex &v);
};
class Graph {
    private:
        std::map<Vertex, std::vector<Vertex> > adj_list_;
    public:
        Graph();
        void addEdge(Vertex u, Vertex v);
        void contract();
        int minCut();
        friend std::ostream& operator<<(std::ostream &os, const Graph &g);
};
