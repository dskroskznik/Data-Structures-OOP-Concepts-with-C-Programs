/************************************************************************************
 * " Assignment #4: PP4 (Dijkstra Algorithm) "                                      *
 *  by Gabriel Adelemoni & Dylan Skroskznik                                         *
 *                                                                                  *
 *   This source file contains the methods to building a Graph structure,           *
 *      referencing the header file to Graph class and Vertex class. The Graph      *
 *      source file provided a function that utilitizes the Dijkstra Algorithm      *
 *      for maneuvering across the graph starting at a vertex built to another      *
 *      vertex to locate the shortest path between begin and end vertices.          *
 *   This source file supplies methods to construct, deconstruct the Graph          *
 *      structure. Adding and Removing the Graph vertices and edges respectively    *
 *      Printing the graph structure by an adjacency list format, getting the       *
 *      path from locating the end label vertex and inserting it between the        *
 *      beginning vertex and the end vertex, and the Dijkstra Algorithm method.     *
 ************************************************************************************/

#include "Graph.hpp"

using namespace std;

Graph::Graph () {};//end constructor

Graph::~Graph () {          
        vertices.clear(); //clears all vertices in graph structure
}//end deconstructor

void Graph::addVertex(string label){
    vertices.insert(vertices.end(), Vertex(label)); //inserts the vertices, by creating the Vertex from the string label 
}//end addVertex

void Graph::removeVertex(string label){    //deleted vertex
    for(int i = 0; i < vertices.size(); i++){   //for loop across vertices with index conditional based on vertices size
        if(vertices[i].getLabel() == label){    //gets label of the vertices if equal label string
            vertices.erase(vertices.begin()+i); //... and erase the vertices (from beginning vertex + index number)
        }
    }

    
    for(vector<Vertex>::iterator it = begin(vertices); it != end(vertices); ++it){ // delete all edges connected to deleted vertex
        for(auto edges : it->getEdgeMap()){                                                       //iterator over edge map to erase
            if(edges.first == label){                                                             //... connected labels to the vertex
                it->edgeMap.erase(label);
            }
        }
    }
}//end removeVertex

void Graph::addEdge(string label1, string label2, unsigned long weight){                  
    for(vector<Vertex>::iterator it = begin(vertices); it != end(vertices); ++it){   //for loop to iterate across beginning vertex vector to the end
        if(it->getLabel() == label1){                                                               //get label is == label1 string and inserts edge to edgeMap by iterator pointer
            it->insertEdgeMap(label2, weight);
        }
        if(it->getLabel() == label2){                                                               //get label is == label2 string and inserts edge to edgeMap by iterator pointer
            it->insertEdgeMap(label1, weight);
        }
    }
}//end addEdge

void Graph::removeEdge(string label1, string label2){                                     // delete all edges connected to deleted vertex
    for(vector<Vertex>::iterator it = begin(vertices); it != end(vertices); ++it){   //for loop to iterate across beginning vertex vector to the end
        for(auto edges : it->getEdgeMap()){                                                         //auto loops through edgeMap from iterator pointer
            if(edges.first == label2 && it->getLabel() == label1){                                  //get label is == label1 string and removes edge from edgeMap by iterator pointer
                it->edgeMap.erase(label2);
            }
            if(edges.first == label1 && it->getLabel() == label2){                                  //get label is == label2 string and removes edge from edgeMap by iterator pointer 
                it->edgeMap.erase(label1);
            }
        }
    }
}//end removeEdge

void Graph::printGraph(){
    for(vector<Vertex>::iterator it = begin(vertices); it != end(vertices); ++it){       //prints method to format a structured graph output
        for(auto edge : it->getEdgeMap()){
            cout << "(" << it->getLabel() << ", " << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}//end printGraph

vector<string> Graph::getPath(string endLabel, map<string, string> pathMap, vector<string> path){
    if(endLabel == ""){                                     //if the endLabel string isnt empty, return vector path
        return path;                                    
    }else{                                                  //else, then insert new path from beginning to end vertex label and return recursively until empty
        path.insert(path.begin(), endLabel);
        return getPath(pathMap[endLabel], pathMap, path);
    }
}//end getPath

unsigned long Graph::shortestPath(string startLabel, string endLabel, vector<string> &path){
    map<string, unsigned long> dist;                                                           //initalize map variable for distance       
    map<string, string> prev;                                                             //initalize map variable for previous    
    for(auto vertex : vertices){                                                                         //for loop auto over vertices to instert distance and prev to hold the main vertices and their labels    
        dist.insert(pair<string, unsigned long>(vertex.getLabel(), INT_MAX));
        prev.insert(pair<string, string>(vertex.getLabel(), ""));
    }
    dist[startLabel] = 0;                                                                                //start off at value 0 for distance travelled

    vector<string> S;                                                                         // vector variabl   e string S
    typedef pair<unsigned long, string> pi;                                                   //build priority queue to hold pair of vertex and adjacent path and vertices 
    priority_queue<pi, vector<pi>, greater<pi>> Q;                                       //... to push in an ordered path that directs to shortest path 
    for(auto vertex : dist){
        Q.push(make_pair(vertex.second, vertex.first));
    }

    while(!Q.empty()){                                                                                  //Dijkstra's Algorithm while loop when the priority queue is not empty to store
        pi uUtil = Q.top();
        string U = uUtil.second;
        Q.pop();
        S.push_back(U);
        for(vector<Vertex>::iterator it = begin(vertices); it != end(vertices); ++it){
            if(it->getLabel() == U){                                                                    // locate the U vertex
                for(auto edge : it->getEdgeMap()){                                                      // loop through every edge
                    if(dist[edge.first] > dist[U] + edge.second){
                        dist[edge.first] = dist[U] + edge.second;
                        Q = priority_queue<pi, vector<pi>, greater<pi>>();               // update the priorty queue
                        for(auto vertex : dist){
                            Q.push(make_pair(vertex.second, vertex.first));
                        }
                        prev[edge.first] = U; // set parent of the edge in the parent map
                    }
                }
                break;
            }
        }
    }
    path = getPath(endLabel, prev, path);   //initialize path veriable with the main shortest path
    return dist[endLabel];
}//end shortestPath (Dijkstra's Algorithm)
