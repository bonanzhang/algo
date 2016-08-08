#include <iostream>
#include <string>
#include <sstream>
#include "graph.h"
int main() {
    int src;
    int dst;
    Graph g;
    std::string line;
    std::stringstream ss;
    while (std::getline(std::cin, line)) {
        ss << line;
        ss >> src >> dst;
        ss.clear();
        Vertex u(src);
        Vertex v(dst);
        g.addEdge(u,v);
    }
    std::vector<std::vector<Vertex> > SCC = g.findStronglyConnectedComponents();
    for (std::vector<std::vector<Vertex> >::iterator s_it = SCC.begin(); s_it != SCC.end(); ++s_it) {
//        for (std::vector<Vertex>::iterator v_it = s_it->begin(); v_it != s_it->end(); ++v_it) {
//            std::cout << *v_it << " ";
//        }
        std::cout << s_it->size() << std::endl;
    }
    return 0;
}
