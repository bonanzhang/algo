#include <iostream>
#include <string>
#include <sstream>
#include "graph.h"
int main() {
    std::string src;
    std::string dst;
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
    std::cout << g << std::endl;
    std::cout << "BFS" << std::endl;
    g.BFS();
    std::cout << "DFS" << std::endl;
    g.DFS();
    return 0;
}
