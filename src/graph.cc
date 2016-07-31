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
    //pick random Vertex
    std::set<Vertex>::iterator u_it(vertices_.begin());
    int u_rand_index = rand() % vertices_.size();
    std::advance(u_it, u_rand_index);
    Vertex u = *u_it;
    //pick random connection
    std::list<Vertex> adjacent_vertices = u.getAdjacentVertices();
    std::list<Vertex>::const_iterator v_it(adjacent_vertices.begin());
    int v_rand_index = rand() % adjacent_vertices.size();
    std::advance(v_it, v_rand_index);
    Vertex v = *v_it;
    std::cout << u.getLabel() << "~" << v.getLabel() << std::endl;
    
}
int Graph::minCut() {
    return 0;
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
