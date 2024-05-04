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
 *      Dijkstra's Algorithm by find the shortest path between two pointed vertices,*
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
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include "GraphBase.hpp"

class Vertex{                                                                       //Vertex class:
    public:                                                                         //public accessible Vertex utlities
        std::string vertex;                                                         //string type for vertex
        std::map<std::string, unsigned long> edgeMap = {};                          //map structure using string and unsigned long type for edgeMap
        Vertex(std::string v) { vertex = v; }                                       //Vertex method to call the vertex string v
        std::string getPoint() { return vertex; }                                   //get vertex point by return string vertex
        std::map<std::string, unsigned long> getEdgeMap() { return edgeMap; }       //map type method getEdgeMap to return the edgeMap map structure for edges
        void insertEdgeMap(std::string point_b, unsigned long weight) 
        {               
            edgeMap.insert(std::pair<std::string, unsigned long>(point_b, weight));  //method to insert the EdgeMap the second vertex point paired with the distance weight and insert to edgeMap map strucuture
        }
};

class Graph : public GraphBase {                                                                                                            //Graph class, inherited from GraphBase                                                                              
    public:                                                                                                                                 //public accessible Graph utlities
        Graph();                                                                                                                            //Graph class constructor
        ~Graph();                                                                                                                           //Graph class deconstructor 
        void addVertex(std::string point);                                                                                                  //void method to add vertex in graph
        void removeVertex(std::string point);                                                                                               //void method to remove the vertex from the graph
        void addEdge(std::string point_a, std::string point_b, unsigned long weight);                                                         //void method to add the edges between vertices in graph
        void removeEdge(std::string point_a, std::string point_b);                                                                            //void method to remove the edges between vertices in graph
        unsigned long shortestPath(std::string startpath, std::string endpath, std::vector<std::string> &path);                           //unsigned long Dijkstra Algorithm method to locate shortest distance between two vertices given
        std::vector<std::string> getPath(std::string endpath, std::map<std::string, std::string> pathMap, std::vector<std::string> path);  //vector built method to get edge path using end vertex point, with pathMap map of path strings, and the final path.
        void printGraph();                                                                                                                  //void method to print the graph structure
        std::vector<Vertex> vertices;                                                                                                       //a vector type variable that declares all vertices type across the graph structure
};

#endif