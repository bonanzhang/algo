#include "graph.h"
//Edge functions
Edge::Edge() {
    vertices_ = std::make_pair<Vertex *, Vertex*>(NULL, NULL);
}
Edge::Edge(Vertex *v1, Vertex *v2) {
    vertices_ = std::make_pair<Vertex *, Vertex *>(v1, v2);
}
Vertex * Edge::getFirstVertex() {
    return vertices_.first;
}
Vertex * Edge::getSecondVertex() {
    return vertices_.second;
}
Vertex::Vertex() {
    label_.clear();
    adjacent_vertices_.clear();
}
//Vertex Functions
Vertex::Vertex(int label) {
    label_.push_back(label);
    adjacent_vertices_.clear();
}
void Vertex::addLabel(int label) {
    label_.push_back(label);
}
void Vertex::addConnection(Vertex *v) {
    adjacent_vertices_.push_back(v);
}
std::string Vertex::getLabelString() const {
    std::stringstream st;
    st << "{";
    for (std::list<int>::const_iterator it=label_.begin(); it != label_.end(); ++it) {
        st << *it;
    }
    st << "}";
    return st.str();
}
std::ostream & operator<<(std::ostream & os, const Vertex & v) {
    os << "Vertex(" << v.getLabelString() << " ";
    for (std::list<Vertex *>::const_iterator it=v.adjacent_vertices_.begin(); it != v.adjacent_vertices_.end(); ++it) {
        Vertex * cur_v = *it;
        os << cur_v->getLabelString();
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
