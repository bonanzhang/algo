#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H
#include "vertex.h"
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
typedef std::vector<std::pair<Vertex, int> > neighbor_list;
typedef std::map<Vertex, neighbor_list> adj_list;
class WeightedGraph {
    public:
         WeightedGraph();
         void addEdge(Vertex u, Vertex v, int dist);
         std::map<Vertex, int> computeShortestPaths(Vertex s);
         friend std::ostream& operator<<(std::ostream &os, const WeightedGraph &wg);
    private:
        adj_list graph_;
        std::vector<Vertex> queue_;
        void insertIntoQueue(Vertex v);
        Vertex findMinimumFromQueue(std::map<Vertex, int> dist);
        void deleteFromQueue(Vertex v);
};
#endif // WEIGHTED_GRAPH_H
