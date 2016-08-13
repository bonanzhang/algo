#include "vertex.h"
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

