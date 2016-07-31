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
        Vertex cur_v;
        for (t_tokenizer::iterator it = tokens.begin(); it != tokens.end(); ++it) {
            if (it == tokens.begin()) {
                cur_v = Vertex(*it);
            } else {
                Vertex v(*it);
                cur_v.addConnection(v);
            }
        }
        g.addVertex(cur_v);
    }
    return g;
}
int main() {
    std::cout << readGraph() << std::endl;
    return 0;
}
