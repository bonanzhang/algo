#include "graph.h"
//Vertex Functions
Vertex::Vertex() {
    label_ = std::string();
}
Vertex::Vertex(std::string label) {
    label_ = label;
}
void Vertex::setLabel(const std::string label) {
    label_ = label;
}
std::string Vertex::getLabel() const {
    return label_;
}
bool Vertex::operator==(const Vertex &other) const {
    return this->getLabel().compare(other.getLabel()) == 0;
}
bool Vertex::operator<(const Vertex &other) const {
    return this->getLabel().compare(other.getLabel()) < 0;
}
std::ostream & operator<<(std::ostream & os, const Vertex & v) {
    os << v.getLabel();
    return os;
}
//Graph Functions
Graph::Graph() {
    adj_list_.clear();
}
void Graph::addEdge(Vertex u, Vertex v) {
    if (adj_list_.find(u) == adj_list_.end()) {
        adj_list_.insert(std::pair<Vertex, std::vector<Vertex> >(u, std::vector<Vertex>()));
    }
    adj_list_.find(u)->second.push_back(v);
}
void Graph::contract() {
    //pick random Vertex
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dis0(0, adj_list_.size()-1);
    std::map<Vertex, std::vector<Vertex> >::const_iterator rand_u_it = adj_list_.begin();
    std::advance(rand_u_it, dis0(mt));
    Vertex u = rand_u_it->first;
    //pick random connection
    std::vector<Vertex> rand_u_connections = rand_u_it->second;
    std::vector<Vertex>::const_iterator rand_v_it = rand_u_connections.begin();
    std::uniform_int_distribution<int> dis1(0, rand_u_connections.size()-1);
    std::advance(rand_v_it, dis1(mt));
    Vertex v = *rand_v_it;
    //append all of v's connections to u
    std::map<Vertex, std::vector<Vertex> >::iterator u_it = adj_list_.find(u);
    std::map<Vertex, std::vector<Vertex> >::iterator v_it = adj_list_.find(v);
    u_it->second.insert(u_it->second.end(), v_it->second.begin(), v_it->second.end());
    //remove v from the graph
    adj_list_.erase(v);
    //replace all vertices with v's label with vertices with u's label
    for (std::map<Vertex, std::vector<Vertex> >::iterator mit=adj_list_.begin(); mit != adj_list_.end(); ++mit) {
        for (std::vector<Vertex>::iterator vit=mit->second.begin(); vit != mit->second.end(); ++vit) {
            if (*vit == v) {
                *vit = u;
            }
        }
    }
    //remove all self edges
    for (std::map<Vertex, std::vector<Vertex> >::iterator mit=adj_list_.begin(); mit != adj_list_.end(); ++mit) {
        for (std::vector<Vertex>::iterator vit=mit->second.begin(); vit != mit->second.end();) {
            if (*vit == mit->first) {
                vit = mit->second.erase(vit);
            } else {
                ++vit;
            }
        }
    }
}
int Graph::minCut() {
    while (adj_list_.size() > 2) {
        contract();
    }
    return adj_list_.begin()->second.size();
}
void Graph::DFS() {
    DFS(adj_list_.begin()->first);
}
void Graph::DFS(Vertex start) {
    std::set<Vertex> visited;
    std::stack<Vertex> s;
    s.push(start);
    while (!s.empty()) {
        Vertex v = s.top();
        std::cout << v << std::endl;
        s.pop();
        std::map<Vertex, std::vector<Vertex> >::iterator v_it = adj_list_.find(v);
        visited.insert(v_it->first);
        std::vector<Vertex> adj = v_it->second;
        for (std::vector<Vertex>::iterator it = adj.begin(); it != adj.end(); ++it) {
            if (visited.find(adj_list_.find(*it)->first) == visited.end()) {
                s.push(*it);
            }
        }
    }
}
void Graph::BFS() {
    BFS(adj_list_.begin()->first);
}
void Graph::BFS(Vertex start) {
    std::set<Vertex> visited;
    std::queue<Vertex> q;
    q.push(start);
    while (!q.empty()) {
        Vertex v = q.front();
        std::cout << v << std::endl;
        q.pop();
        std::map<Vertex, std::vector<Vertex> >::iterator v_it = adj_list_.find(v);
        visited.insert(v_it->first);
        std::vector<Vertex> adj = v_it->second;
        for (std::vector<Vertex>::iterator it = adj.begin(); it != adj.end(); ++it) {
            if (visited.find(adj_list_.find(*it)->first) == visited.end()) {
                q.push(*it);
            }
        }
    }
}
std::ostream & operator<<(std::ostream & os, const Graph & g) {
    os << "Graph(" << std::endl;
    for (std::map<Vertex, std::vector<Vertex> >::const_iterator mit=g.adj_list_.begin(); mit != g.adj_list_.end(); ++mit) {
        os << "  " << mit->first << "~";
        std::vector<Vertex> adj = mit->second;
        for (std::vector<Vertex>::const_iterator vit=adj.begin(); vit != adj.end(); ++vit) {
            os << (vit == adj.begin() ? "" : ",") << *vit;
        }
        os << std::endl;
        
    }
    os << ")";
    return os;
}
