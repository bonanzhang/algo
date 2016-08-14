#include <string>
#include <iostream>
#include <boost/tokenizer.hpp>
#include "weighted_graph.h"
typedef boost::tokenizer<boost::char_separator<char> > t_tokenizer;
WeightedGraph readGraph() {
    WeightedGraph wg;
    std::string line;
    while (std::getline(std::cin, line)) {
        boost::char_separator<char> tab_sep("\t");
        t_tokenizer line_tokens(line, tab_sep);
        Vertex u;
        for (t_tokenizer::iterator l_it = line_tokens.begin(); l_it != line_tokens.end(); ++l_it) {
            if (l_it == line_tokens.begin()) {
                u = Vertex(std::stoi(*l_it));
            } else {
                boost::char_separator<char> comma_sep(",");
                t_tokenizer vertex_tokens(*l_it, comma_sep);
                t_tokenizer::iterator v_it = vertex_tokens.begin(); 
                Vertex v(std::stoi(*v_it));
                ++v_it;
                int dist = std::stoi(*v_it);
                wg.addEdge(u, v, dist);
            }
        }
    }
    return wg;
}
int main() {
    WeightedGraph wg = readGraph();
    std::map<Vertex, int> dist = wg.computeShortestPaths(Vertex(1));
    for (std::map<Vertex, int>::const_iterator it = dist.begin(); it != dist.end(); ++it) {
        std::cout << it->first << "," << it->second << std::endl;
    }
    return 0;
}
