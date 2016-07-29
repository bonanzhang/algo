#include <list>
#include <string>
#include <sstream>
#include <climits>
#include <iostream>
class Vertex {
    private:
        std::list<int> label_;
        std::list<Vertex *> adjacent_vertices_;
    public:
        Vertex();
        Vertex(int label);
        void addLabel(int label);
        void addConnection(Vertex *v);
        std::string getLabelString() const;
        friend std::ostream& operator<<(std::ostream &os, const Vertex &v);
};
class Edge {
    private:
        std::pair<Vertex *, Vertex *> vertices_;
    public:
        Edge();
        Edge(Vertex *v1, Vertex *v2);
        Vertex * getFirstVertex();
        Vertex * getSecondVertex();
};
class Graph {
    private:
        std::list<Vertex *> vertices_;
        std::list<Edge *> edges_;
    public:
        Graph();
        void addVertex(Vertex *v);
        void addEdge(Edge *e);
        int minCut();
        friend std::ostream& operator<<(std::ostream &os, const Graph &g);
};
