#include <list>
#include <set>
#include <string>
#include <sstream>
#include <climits>
#include <iostream>
#include <cstdlib>
class Vertex {
    private:
        std::string label_;
        std::list<Vertex> adjacent_vertices_;
    public:
        Vertex();
        Vertex(std::string label);
        void setLabel(std::string label);
        std::string getLabel() const;
        std::list<Vertex> getAdjacentVertices() const;
        void addConnection(Vertex v);
        bool operator==(const Vertex & other) const;
        bool operator!=(const Vertex & other) const;
        bool operator<(const Vertex & other) const;
        friend std::ostream& operator<<(std::ostream &os, const Vertex &v);
};
class Graph {
    private:
        std::set<Vertex> vertices_;
    public:
        Graph();
        void addVertex(Vertex v);
        bool hasVertex(Vertex v);
        void contract();
        int minCut();
        friend std::ostream& operator<<(std::ostream &os, const Graph &g);
};
