#ifndef GRAPH_H
#define GRAPH_H
#include "Edges.hpp"
#include "Vertex.hpp"
#include "GraphBase.hpp"

class Graph : public GraphBase {
    private: 
        std::vector<Vertex*> vertices;

    public:
        void addVertex(std::string label);
        void addEdge(std::string label1, std::string label2, unsigned long weight);
        void removeVertex(std::string label);
        void removeEdge(std::string label1, std::string label2);
        unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
};

#endif