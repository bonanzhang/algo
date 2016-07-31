#include "graph.h"
//Vertex Functions
Vertex::Vertex() {
    label_.clear();
    adjacent_vertices_.clear();
}
Vertex::Vertex(std::string label) {
    label_ = label;
    adjacent_vertices_.clear();
}
void Vertex::setLabel(std::string label) {
    label_ = label;
}
std::string Vertex::getLabel() const {
    return label_;
}
std::list<Vertex> Vertex::getAdjacentVertices() const {
    return adjacent_vertices_;
}
void Vertex::addConnection(Vertex v) {
    adjacent_vertices_.push_back(v);
}
bool Vertex::operator==(const Vertex &other) const {
    return this->getLabel().compare(other.getLabel()) == 0;
}
bool Vertex::operator!=(const Vertex &other) const {
    return !(*this == other);
}
bool Vertex::operator<(const Vertex &other) const {
    return this->getLabel().compare(other.getLabel()) < 0;
}
std::ostream & operator<<(std::ostream & os, const Vertex & v) {
    os << "Vertex(" << v.getLabel() << " - ";
    for (std::list<Vertex>::const_iterator it=v.adjacent_vertices_.begin(); it != v.adjacent_vertices_.end(); ++it) {
        Vertex cur_v = *it;
        os << (it == v.adjacent_vertices_.begin() ? "" : " ") << cur_v.getLabel();
    }
    os << ")";
    return os;
}
//Graph Functions
Graph::Graph() {
    vertices_.clear();
}
void Graph::contract() {
    std::srand(std::time(0));
    //pick random Vertex
    std::set<Vertex>::iterator rand_u_it(vertices_.begin());
    int u_rand_index = rand() % vertices_.size();
    std::advance(rand_u_it, u_rand_index);
    Vertex u = *rand_u_it;
    std::string replace = u.getLabel();
    //pick random connection
    std::list<Vertex> adjacent_vertices = u.getAdjacentVertices();
    std::list<Vertex>::const_iterator rand_v_it(adjacent_vertices.begin());
    int v_rand_index = rand() % adjacent_vertices.size();
    std::advance(rand_v_it, v_rand_index);
    Vertex v = *rand_v_it;
//    std::cout << u.getLabel() << "~" << v.getLabel() << std::endl;
//    std::cout << "before append " << std::endl << *this << std::endl;
    //append all of v's connections to u
    std::set<Vertex>::iterator u_it;
    std::set<Vertex>::iterator v_it;
    u_it = vertices_.find(u);
    v_it = vertices_.find(v);
    Vertex cur_u = Vertex(u.getLabel());
    std::list<Vertex> u_adj = u_it->getAdjacentVertices();
    for (std::list<Vertex>::const_iterator adj_it = u_adj.begin(); adj_it != u_adj.end(); ++adj_it) {
        cur_u.addConnection(Vertex(adj_it->getLabel()));
    }
    std::list<Vertex> v_adj = v_it->getAdjacentVertices();
    for (std::list<Vertex>::const_iterator adj_it = v_adj.begin(); adj_it != v_adj.end(); ++adj_it) {
        cur_u.addConnection(Vertex(adj_it->getLabel()));
    }
    vertices_.erase(u_it);
    vertices_.insert(cur_u);
    
//    std::cout << "after append " << std::endl << *this << std::endl;
    //remove v from the graph
    v_it = vertices_.find(v);
    vertices_.erase(v_it);
//    std::cout << "after remove v " << std::endl << *this << std::endl;
    //replace all vertices with v's label with vertices with u's label
    std::set<Vertex> copy;
    for (v_it = vertices_.begin(); v_it != vertices_.end(); ++v_it) {
        Vertex cur_v(v_it->getLabel());
        std::list<Vertex> v_adj = v_it->getAdjacentVertices();
        for (std::list<Vertex>::const_iterator adj_it = v_adj.begin(); adj_it != v_adj.end(); ++adj_it) {
            if (v == *adj_it) {
                cur_v.addConnection(Vertex(replace));
            } else {
                cur_v.addConnection(Vertex(adj_it->getLabel()));
            }
        }
        copy.insert(cur_v);
    }
    vertices_ = copy;
//    std::cout << "after replace " << std::endl << *this << std::endl;
    //remove all self edges
    copy.clear();
    for (v_it = vertices_.begin(); v_it != vertices_.end(); ++v_it) {
        std::string self_label = v_it->getLabel();
        Vertex cur_v(self_label);
        std::list<Vertex> v_adj = v_it->getAdjacentVertices();
        for (std::list<Vertex>::const_iterator adj_it = v_adj.begin(); adj_it != v_adj.end(); ++adj_it) {
            if (adj_it->getLabel().compare(self_label) != 0) {
                cur_v.addConnection(Vertex(adj_it->getLabel()));
            }
        }
        copy.insert(cur_v);
    }
    vertices_ = copy;
//    std::cout << "after self edge removal " << std::endl << *this << std::endl;
 
}
int Graph::minCut() {
    while (vertices_.size() > 2) {
        contract();
    }
    return vertices_.begin()->getAdjacentVertices().size();
}
void Graph::addVertex(Vertex v) {
    vertices_.insert(v);
}
bool Graph::hasVertex(Vertex v) {
    return vertices_.find(v) != vertices_.end();
}
std::ostream & operator<<(std::ostream & os, const Graph & g) {
    os << "Graph(" << std::endl;
    for (std::set<Vertex>::const_iterator it=g.vertices_.begin(); it != g.vertices_.end(); ++it) {
        Vertex cur_v = *it;
        os << "  " << cur_v << std::endl;
    }
    os << ")";
    return os;
}
