#include <string>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include "graph.h"
typedef boost::tokenizer<boost::char_separator<char> > t_tokenizer;
int main() {
    std::cout << "Building a Graph from stdin" << std::endl;
    Graph g;
    std::string line;
    boost::char_separator<char> sep("\t");
    while (std::getline(std::cin, line)) {
        t_tokenizer tokens(line, sep);
        for (t_tokenizer::iterator it = tokens.begin(); it != tokens.end(); ++it) {
            Vertex * cur_v;
            if (it == tokens.begin()) {
            //    std::cout << "Vertex:";
                cur_v = new Vertex(*it);
                g.addVertex(cur_v);
            } else {
            //    std::cout << "Adjacent:";
                Vertex *v = new Vertex(*it);
                g.addVertex(v);
                Edge * e = new Edge(cur_v, v);
                g.addEdge(e);
            }
            //std::cout << *it << std::endl;
        }
    }
    std::cout << g << std::endl;
    return 0;
}
