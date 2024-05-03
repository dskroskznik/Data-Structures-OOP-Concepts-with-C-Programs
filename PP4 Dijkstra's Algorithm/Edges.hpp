#ifndef EDGE_H
#define EDGE_H

#include "Vertex.hpp"

class Edges {
    public:
        Vertex *node1;
        Vertex *node2;
        friend class Vertices;
        friend class Graph;
        int weight;
        int edge_pos;
};

#endif