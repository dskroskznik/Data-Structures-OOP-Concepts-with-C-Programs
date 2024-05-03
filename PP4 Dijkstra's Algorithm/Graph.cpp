#include "Graph.hpp"
#include <iostream>
#include <iostream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <climits>


void Graph::addEdge(std::string label1, std::string label2, unsigned long weight)
{
    std::vector<Edges*> edges;
    Edges *new_edge = new Edges;
    int L1, L2 = 0;

    do {
        if(label1==vertices.at(L1)->vertex_label) { break; }
        ++L1;
    }while(vertices.size() > L1);

    do { 
        if(label2==vertices.at(L2)->vertex_label) { break; }   
        ++L2;
    } while (vertices.size() > L2);

    edges.push_back(new_edge);
    edges.back()->weight;
    edges.back()->edge_pos = edges.size()-1;
    edges.back()->node2 = vertices.at(L1); c
    edges.back()->node1 = vertices.at(L2);
}

void Vertex::inputEdgePos(int p) 
{
    vertex_pos=p;
}

void Vertex::destroyEdges(std::string v1,std::string v2)
{
    int size_index=0; 
    while(size_index < edges.size()){
        if(v1!=edges.at(size_index)->node1->vertex_label && 
            v2!=edges.at(size_index)->node2->vertex_label) { 
                ++size_index; 
        }        
        else { 
            edges.erase(edges.begin()+size_index);
            break;
        }
    }
}

void Vertex::connectEdgeVertex(unsigned long w, Vertex *new_node)
{
    Edges *new_edge = new Edges;
    edges.push_back(new_edge);
    edges.back()->weight = w;
    edges.back()->edge_pos = edges.size()-1;
    edges.back()->node2 = new_node;
    edges.back()->node1 = this;
}

