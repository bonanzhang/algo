#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "graph.h"
int main() {
    int src;
    int dst;
    Graph G;
    Graph G_rev;
    std::string line;
    std::stringstream ss;
    std::cout << "building graph" << std::endl;
    while (std::getline(std::cin, line)) {
        ss << line;
        ss >> src >> dst;
        ss.clear();
        Vertex u(src);
        Vertex v(dst);
        G.addEdge(u,v);
        G_rev.addEdge(v,u);
    }
    std::cout << G_rev << std::endl;
    std::cout << "running first pass" << std::endl;
    std::vector<Vertex> order = G_rev.DFS();
    std::cout << "book keeping" << std::endl;
    std::reverse(order.begin(), order.end());

    std::cout << "order:" << std::endl;
    for (std::vector<Vertex>::iterator it = order.begin(); it != order.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "running second pass" << std::endl;
    std::vector<std::vector<Vertex> > SCC = G.SCC_second_pass(order);
    
    std::cout << "results:" << std::endl;
    for (std::vector<std::vector<Vertex> >::iterator s_it = SCC.begin(); s_it != SCC.end(); ++s_it) {
        for (std::vector<Vertex>::iterator v_it = s_it->begin(); v_it != s_it->end(); ++v_it) {
            std::cout << *v_it << " ";
        }
        std::cout << "--" << s_it->size() << std::endl;
    }
    return 0;
}
