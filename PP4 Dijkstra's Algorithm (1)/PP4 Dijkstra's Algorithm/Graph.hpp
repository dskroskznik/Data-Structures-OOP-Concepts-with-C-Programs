/************************************************************************************
 * " Assignment #4: PP4 (Dijkstra Algorithm) "                                      *
 *  by Gabriel Adelemoni & Dylan Skroskznik                                         *
 *                                                                                  *
 *   This header file for the Graph structure provides the necessary foundational   *
 *      classes Vertex, and Graph (inherited by GraphBase), which include           *
 *      their accessible method declarations and function variables, some of which  *
 *      are taken from the many standard c++ library functions as well.             *
 *   The Vertex class includes necessary initializations of variables and functions *
 *      that help detect and handle vertices across the graph structure, and the    *
 *      vertices allow us to pin point different edges connected to different       *
 *      adjacent vertices too.                                                      *
 *   The Graph class includes necessary graph methods inherted from the GraphBase   *
 *      class to handle the methods to creating and deleting the vertices and edges *
 *      to the Graph structure build. Additionally, since our goal is to utilize    *
 *      Dijkstra's Algorithm by find the shortest path between two labeled vertices,*
 *      we have the shortest path method and the get path methods for optimal       *
 *      locating performance for the algorithm.                                     *
 ************************************************************************************/

#ifndef GRAPH_HPP
#define GRAPH_HPP

//include standard c++ libraries
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include "GraphBase.hpp"

using namespace std;

class Vertex{                                                                       //Vertex class:
    public:                                                                         //public accessible Vertex utlities
        string vertex;                                                         //string type for vertex
        map<string, unsigned long> edgeMap = {};                          //map structure using string and unsigned long type for edgeMap
        Vertex(string v){ vertex = v; }                                        //Vertex method to call the vertex string v
        string getLabel(){ return vertex; }                                    //get vertex label by return string vertex
        map<string, unsigned long> getEdgeMap(){ return edgeMap; }        //map type method getEdgeMap to return the edgeMap map structure for edges
        void insertEdgeMap(string label2, unsigned long weight){               //void method to insert the EdgeMap the second vertex label paired with the distance weight and insert to edgeMap map strucuture
            edgeMap.insert(pair<string, unsigned long>(label2, weight));
        }
};

class Graph : public GraphBase {                                                                                                            //Graph class, inherited from GraphBase                                                                              
    public:                                                                                                                                 //public accessible Graph utlities
        Graph();                                                                                                                            //Graph class constructor
        ~Graph();                                                                                                                           //Graph class deconstructor 
        void addVertex(string label);                                                                                                  //void method to add vertex in graph
        void removeVertex(string label);                                                                                               //void method to remove the vertex from the graph
        void addEdge(string label1, string label2, unsigned long weight);                                                         //void method to add the edges between vertices in graph
        void removeEdge(string label1, string label2);                                                                            //void method to remove the edges between vertices in graph
        unsigned long shortestPath(string startLabel, string endLabel, vector<string> &path);                           //unsigned long Dijkstra Algorithm method to locate shortest distance between two vertices given
        vector<string> getPath(string endLabel, map<string, string> pathMap, vector<string> path);  //vector built method to get edge path using end vertex label, with pathMap map of path strings, and the final path.
        void printGraph();                                                                                                                  //void method to print the graph structure
        vector<Vertex> vertices;                                                                                                       //a vector type variable that declares all vertices type across the graph structure
};

#endif
