#include "graph.h"
//Edge functions
Edge::Edge() {
}
Edge::Edge(Vertex *v1, Vertex *v2) {
    vertices_.push_back(v1);
    vertices_.push_back(v2);
}
Vertex * Edge::getFirstVertex() {
    return vertices_.front();
}
Vertex * Edge::getSecondVertex() {
    return vertices_.back();
}
Vertex::Vertex() {
    adjacent_vertices_.clear();
}
//Vertex Functions
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
void Vertex::addConnection(Vertex *v) {
    adjacent_vertices_.push_back(v);
}
std::ostream & operator<<(std::ostream & os, const Vertex & v) {
    os << "Vertex(" << v.getLabel() << "-";
    for (std::list<Vertex *>::const_iterator it=v.adjacent_vertices_.begin(); it != v.adjacent_vertices_.end(); ++it) {
        Vertex * cur_v = *it;
        os << (it == v.adjacent_vertices_.begin() ? "" : ",") << cur_v->getLabel();
    }
    os << ")";
    return os;
}
//Graph Functions
Graph::Graph() {
    vertices_.clear();
    edges_.clear();
}
int Graph::minCut() {
    return 0;
}
void Graph::contract() {
    int rand_edge_index = rand() % edges_.size();
    std::cout << "randomly picked " << rand_edge_index << " between 0 and " << edges_.size()-1 << std::endl;
}
void Graph::addVertex(Vertex *v) {
    vertices_.push_back(v);
}
void Graph::addEdge(Edge *e) {
    edges_.push_back(e);
    Vertex *v1 = e->getFirstVertex();
    Vertex *v2 = e->getSecondVertex();
    for (std::list<Vertex *>::iterator it=vertices_.begin(); it != vertices_.end(); ++it) {
        Vertex * cur_v = *it;
        if (cur_v == v1) {
            cur_v->addConnection(v2);
        }
        if (cur_v == v2) {
            cur_v->addConnection(v1);
        }
    }
}
std::ostream & operator<<(std::ostream & os, const Graph & g) {
    os << "Graph(" << std::endl;
    for (std::list<Vertex *>::const_iterator it=g.vertices_.begin(); it != g.vertices_.end(); ++it) {
        Vertex * cur_v = *it;
        os << "  " << *cur_v << std::endl;
    }
    os << ")" << std::endl;;
    return os;
}
