#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H
#include "vertex.h"
#include <map>
#include <vector>
#include <iostream>
typedef std::map<Vertex, std::vector<std::pair<Vertex, int> > > adj_list;
class WeightedGraph {
    public:
         WeightedGraph();
         void addEdge(Vertex u, Vertex v, int dist);
         friend std::ostream& operator<<(std::ostream &os, const WeightedGraph &wg);
    private:
        adj_list graph_;
};
#endif // WEIGHTED_GRAPH_H
