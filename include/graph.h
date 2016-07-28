#include <list>
#include <climits>
class Vertex {
    private:
        std::list<int> label_;
        std::list<Edge> adjacent_vertices_;
};
class Edge {
    private:
        std::pair<Vertex, Vertex> vertices_;
};
class Graph {
    private:
        std::list<Vertex> vertices_;
        std::list<Vertex> edges_;
    public:
        int minCut();
};
