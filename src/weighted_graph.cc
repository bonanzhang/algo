#include "weighted_graph.h"
WeightedGraph::WeightedGraph() {
    graph_.clear();
}
void WeightedGraph::addEdge(Vertex u, Vertex v, int dist) {
    if (graph_.find(u) != graph_.end()) {
        graph_.insert(std::pair<Vertex, std::vector<std::pair<Vertex, int> > >(u, vector<Vertex, int>());
    }
    graph_.find(u)->second.push_back(std::pair<Vertex, int>(v, dist));
}
std::ostream& operator<<(std::ostream &os, const WeightedGraph &wg) {
    return os;
}
