#include "weighted_graph.h"
WeightedGraph::WeightedGraph() {
    graph_.clear();
}
void WeightedGraph::addEdge(Vertex u, Vertex v, int l) {
    if (graph_.find(u) != graph_.end()) {
        graph_.insert(std::pair<Vertex, neighbor_list >(u, neighbor_list()));
    }
    graph_.find(u)->second.push_back(std::pair<Vertex, int>(v, l));
}
void WeightedGraph::insertIntoQueue(Vertex v) {
    queue_.push_back(v);
}
Vertex WeightedGraph::findMinimumFromQueue(std::map<Vertex, int> dist) {
    Vertex res;
    int cur_min = 2000000;
    for (std::vector<Vertex>::const_iterator it = queue_.begin(); it != queue_.end(); it++) {
        if (dist[*it] < cur_min) {
            cur_min = dist[*it];
            res = *it;
        }
    }
    return res;
}
void WeightedGraph::deleteFromQueue(Vertex v) {
    queue_.erase(std::find(queue_.begin(), queue_.end(), v));
}
std::map<Vertex, int> WeightedGraph::computeShortestPaths(Vertex s) {
    //vertex set Q
    queue_.clear();
    //distances dist
    std::map<Vertex, int> dist;
    //for each v in G
    for (adj_list::const_iterator it = graph_.begin(); it != graph_.end(); ++it) {
        Vertex v = it->first;
        //dist[v] = INFINITE
        dist[v] = 1000000;
        //add v to Q
        insertIntoQueue(v);
    }
    //dist[s] = 0;
    dist[s] = 0;
    //while Q is not empty
    while (queue_.size() > 0) {
        //u = min(Q)
        Vertex u = findMinimumFromQueue(dist);
        //remove u from Q
        deleteFromQueue(u);
        //for each neighbor v of u
        neighbor_list nl;
        if (graph_.find(u) != graph_.end()) {
            nl = graph_.find(u)->second;
        }
        for (neighbor_list::const_iterator it = nl.begin(); it != nl.end(); ++it) {
            //alt = dist[v] + l(u,v)
            Vertex v = it->first;
            int l_uv = it->second;
            int alt = dist[v] + l_uv;
            //if alt < dist[v]
            if (alt < dist[v]) {
                //dist[v] = alt
                dist[v] = alt;
            }
        }
    }
    return dist;
}
std::ostream& operator<<(std::ostream &os, const WeightedGraph &wg) {
    return os;
}
