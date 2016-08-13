#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
class Vertex {
    private:
        int label_;
    public:
        Vertex();

        Vertex(int label);
        void setLabel(const int label);
        int getLabel() const;

        bool operator==(const Vertex & other) const;
        bool operator<(const Vertex & other) const;
        friend std::ostream& operator<<(std::ostream &os, const Vertex &v);
};
#endif // VERTEX_H
