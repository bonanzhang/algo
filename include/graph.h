#include <list>
#include <set>
#include <string>
#include <sstream>
#include <climits>
#include <iostream>
class Vertex {
    private:
        std::string label_;
        std::list<Vertex> adjacent_vertices_;
    public:
        Vertex();
        Vertex(std::string label);
        void setLabel(std::string label);
        std::string getLabel() const;
        void addConnection(Vertex v);
        bool operator==(const Vertex & other) const;
        bool operator!=(const Vertex & other) const;
        bool operator<(const Vertex & other) const;
        friend std::ostream& operator<<(std::ostream &os, const Vertex &v);
};
class Edge {
    private:
        std::list<Vertex> vertices_;
    public:
        Edge();
        Edge(Vertex v1, Vertex v2);
        Vertex getFirstVertex() const;
        Vertex getSecondVertex() const;
        friend std::ostream& operator<<(std::ostream &os, const Edge &e);
};
class Graph {
    private:
        std::set<Vertex> vertices_;
        std::list<Edge> edges_;
    public:
        Graph();
        void addVertex(Vertex v);
        bool hasVertex(Vertex v);
        void addEdge(Edge e);
        int minCut();
        friend std::ostream& operator<<(std::ostream &os, const Graph &g);
};
