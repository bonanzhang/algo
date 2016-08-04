#include <string>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include "graph.h"
typedef boost::tokenizer<boost::char_separator<char> > t_tokenizer;
Graph readGraph() {
    Graph g;
    std::string line;
    boost::char_separator<char> sep("\t");
    while (std::getline(std::cin, line)) {
        t_tokenizer tokens(line, sep);
        Vertex u;
        for (t_tokenizer::iterator it = tokens.begin(); it != tokens.end(); ++it) {
            if (it == tokens.begin()) {
                u = Vertex(*it);
            } else {
                Vertex v(*it);
                g.addEdge(u, v);
            }
        }
    }
    return g;
}
int main() {
    Graph g = readGraph();
    int min = 1000;
    int cur;
    for (int i = 0; i < 100; i++) {
        Graph cur_g = g;
        cur = cur_g.minCut();
        if (cur < min) {
           min = cur;
        }
        std::cout << "random trial " << i+1 << " got: " << cur << " minimum is: " << min << std::endl;
    }
    return 0;
}
