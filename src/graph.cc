#include "graph.h"
int Graph::minCut() {
    int min = INT_MAX;
    for (int trial = 0; trial < 50; trial++) {
        Graph trial_graph = this.copy();
        while (trial_graph.vertices_.size() > 2) {
            //contract   
        }
        min = trial_graph.vertices[0].adjacent_vertices_.size();
    }
}
