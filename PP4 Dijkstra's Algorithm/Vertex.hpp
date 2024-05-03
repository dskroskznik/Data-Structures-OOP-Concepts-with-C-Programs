#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>

class Vertex {
    private:
        friend class Edges;
        friend class Graph;
        std::vector<Edges*> edges;
        std::string vertex_label;
        int vertex_pos;

    public:
        void inputEdgePos(int p);
        void destroyEdges(std::string v1, std::string v2);
        void connectEdgeVertex(unsigned long w, Vertex *k);
};

class Edges;

#endif

