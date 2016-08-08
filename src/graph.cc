#include "graph.h"
//Vertex Functions
Vertex::Vertex() {
    label_ = 0;
}
Vertex::Vertex(int label) {
    label_ = label;
}
void Vertex::setLabel(const int label) {
    label_ = label;
}
int Vertex::getLabel() const {
    return label_;
}
bool Vertex::operator==(const Vertex &other) const {
    return this->getLabel() == other.getLabel();
}
bool Vertex::operator<(const Vertex &other) const {
    return this->getLabel() < other.getLabel();
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

    if (rev_graph_.find(v) == rev_graph_.end()) {
        rev_graph_.insert(std::pair<Vertex, std::vector<Vertex> >(v, std::vector<Vertex>()));
    }
    rev_graph_.find(v)->second.push_back(u);
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
std::vector<std::vector<Vertex> > Graph::DFS(std::vector<Vertex> order) {
    std::vector<std::vector<Vertex> > result;
    visited_.clear();
    for (std::vector<Vertex>::iterator it = order.begin(); it != order.end(); ++it) {
        if (visited_.find(*it) == visited_.end()) {
            std::vector<Vertex> partial = DFS(*it);
            result.push_back(partial);
        }
    }
    return result;
}
std::vector<Vertex> Graph::DFS(Vertex start) {
    std::vector<Vertex> result;
    std::stack<Vertex> s;
    std::set<Vertex> seen;
    result.clear();
    s.push(start);
    while (!s.empty()) {
        Vertex v = s.top();
        s.pop();
        if (visited_.find(v) == visited_.end()) {
            result.push_back(v);
            visited_.insert(v);
            s.push(v);
            if (adj_list_.find(v) != adj_list_.end()) {
                std::vector<Vertex> adj = adj_list_.find(v)->second;
                for (std::vector<Vertex>::iterator it = adj.begin(); it != adj.end(); ++it) {
                    if (visited_.find(*it) == visited_.end()) {
                        s.push(*it);
                    }
                }
            }
        } else {
            if (seen.find(v) == seen.end()) {
                seen.insert(v);
                finished_.push_back(v);
            }
        }
    }
    return result;
}
std::vector<Vertex> Graph::DFS_rev() {
    std::vector<Vertex> result;
    visited_.clear();
    for (std::map<Vertex, std::vector<Vertex> >::iterator it = rev_graph_.begin(); it != rev_graph_.end(); ++it) {
        if (visited_.find(it->first) == visited_.end()) {
            std::vector<Vertex> partial = DFS_rev(it->first);
            result.insert(result.end(), partial.begin(), partial.end());
        }
    }
    std::reverse(finished_.begin(), finished_.end());
    return result;
}
std::vector<Vertex> Graph::DFS_rev(Vertex start) {
    std::vector<Vertex> result;
    std::stack<Vertex> s;
    std::set<Vertex> seen;
    result.clear();
    s.push(start);
    while (!s.empty()) {
        Vertex v = s.top();
        s.pop();
        if (visited_.find(v) == visited_.end()) {
            result.push_back(v);
            visited_.insert(v);
            s.push(v);
            if (rev_graph_.find(v) != rev_graph_.end()) {
                std::vector<Vertex> adj = rev_graph_.find(v)->second;
                for (std::vector<Vertex>::iterator it = adj.begin(); it != adj.end(); ++it) {
                    if (visited_.find(*it) == visited_.end()) {
                        s.push(*it);
                    }
                }
            }
        } else {
            if (seen.find(v) == seen.end()) {
                seen.insert(v);
                finished_.push_back(v);
            }
        }
    }
    return result;
}
std::vector<Vertex> Graph::BFS(Vertex start) {
    std::vector<Vertex> result;
    std::queue<Vertex> q;
    q.push(start);
    while (!q.empty()) {
        Vertex v = q.front();
        q.pop();
        result.push_back(v);
        visited_.insert(v);
        if (adj_list_.find(v) != adj_list_.end()) {
            std::vector<Vertex> adj = adj_list_.find(v)->second;
            for (std::vector<Vertex>::iterator it = adj.begin(); it != adj.end(); ++it) {
                if (visited_.find(*it) == visited_.end()) {
                    q.push(*it);
                }
            }
        }
    }
    return result;
}
int Graph::minCut() {
    while (adj_list_.size() > 2) {
        contract();
    }
    return adj_list_.begin()->second.size();
}
std::vector<Vertex> Graph::DFS() {
    std::vector<Vertex> result;
    visited_.clear();
    for (std::map<Vertex, std::vector<Vertex> >::iterator it = adj_list_.begin(); it != adj_list_.end(); ++it) {
        if (visited_.find(it->first) == visited_.end()) {
            std::vector<Vertex> partial = DFS(it->first);
            result.insert(result.end(), partial.begin(), partial.end());
        }
    }
    return result;
}
std::vector<Vertex> Graph::BFS() {
    std::vector<Vertex> result;
    visited_.clear();
    for (std::map<Vertex, std::vector<Vertex> >::iterator it = adj_list_.begin(); it != adj_list_.end(); ++it) {
        if (visited_.find(it->first) == visited_.end()) {
            std::vector<Vertex> partial = BFS(it->first);
            result.insert(result.end(), partial.begin(), partial.end());
        }
    }
    return result;
}
std::vector<std::vector<Vertex> > Graph::findStronglyConnectedComponents() {
    std::vector<std::vector<Vertex> > result;
    DFS_rev();
    return DFS(finished_);
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
