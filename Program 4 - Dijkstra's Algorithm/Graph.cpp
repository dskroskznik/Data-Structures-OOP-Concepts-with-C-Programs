/************************************************************************************
 * " Programming Project #4: Pair Programming (Dijkstra's Algorithm) "                                     *
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

Graph::Graph () {};//end constructor

Graph::~Graph () {          
        vertices.clear(); //clears all vertices in graph structure
}//end deconstructor

void Graph::addVertex(std::string point){
    vertices.insert(vertices.end(), Vertex(point)); //inserts the vertices, by creating the Vertex from the string label 
}//end addVertex

void Graph::removeVertex(std::string point){    //deleted vertex
    for(int i = 0; i < vertices.size(); i++){   //for loop across vertices with index conditional based on vertices size
        if(vertices[i].getPoint() == point){    //gets label of the vertices if equal label string
            vertices.erase(vertices.begin()+i); //... and erase the vertices (from beginning vertex + index number)
        }
    }

    
    for(std::vector<Vertex>::iterator it = std::begin(vertices); it != std::end(vertices); ++it){ // delete all edges connected to deleted vertex
        for(auto edges : it->getEdgeMap()){                                                       //iterator over edge map to erase
            if(edges.first == point){                                                             //... connected labels to the vertex
                it->edgeMap.erase(point);
            }
        }
    }
}//end removeVertex

void Graph::addEdge(std::string point_a, std::string point_b, unsigned long weight){                  
    for(std::vector<Vertex>::iterator it = std::begin(vertices); it != std::end(vertices); ++it){   //for loop to iterate across beginning vertex vector to the end
        if(it->getPoint() == point_a){                                                               //get label is == point_a string and inserts edge to edgeMap by iterator pointer
            it->insertEdgeMap(point_b, weight);
        }
        if(it->getPoint() == point_b){                                                               //get label is == point_b string and inserts edge to edgeMap by iterator pointer
            it->insertEdgeMap(point_a, weight);
        }
    }
}//end addEdge

void Graph::removeEdge(std::string point_a, std::string point_b){                                     // delete all edges connected to deleted vertex
    for(std::vector<Vertex>::iterator it = std::begin(vertices); it != std::end(vertices); ++it){   //for loop to iterate across beginning vertex vector to the end
        for(auto edges : it->getEdgeMap()){                                                         //auto loops through edgeMap from iterator pointer
            if(edges.first == point_b && it->getPoint() == point_a){                                  //get label is == point_a string and removes edge from edgeMap by iterator pointer
                it->edgeMap.erase(point_b);
            }
            if(edges.first == point_a && it->getPoint() == point_b){                                  //get label is == point_b string and removes edge from edgeMap by iterator pointer 
                it->edgeMap.erase(point_a);
            }
        }
    }
}//end removeEdge

void Graph::printGraph(){
    for(std::vector<Vertex>::iterator it = std::begin(vertices); it != std::end(vertices); ++it){       //prints method to format a structured graph output
        for(auto edge : it->getEdgeMap()){
            std::cout << "(" << it->getPoint() << ", " << edge.first << ", " << edge.second << ") ";
        }
        std::cout << std::endl;
    }
}//end printGraph

std::vector<std::string> Graph::getPath(std::string endpath, std::map<std::string, std::string> pathMap, std::vector<std::string> path){
    if(endpath == ""){                                     //if the endpath string isnt empty, return vector path
        return path;                                    
    }else{                                                  //else, then insert new path from beginning to end vertex label and return recursively until empty
        path.insert(path.begin(), endpath);
        return getPath(pathMap[endpath], pathMap, path);
    }
}//end getPath

unsigned long Graph::shortestPath(std::string startpath, std::string endpath, std::vector<std::string> &path){
    std::map<std::string, unsigned long> dist;                                                           //initalize map variable for distance       
    std::map<std::string, std::string> prev;                                                             //initalize map variable for previous    
    for(auto v : vertices){                                                                         //for loop auto over vertices to instert distance and prev to hold the main vertices and their labels    
        dist.insert(std::pair<std::string, unsigned long>(v.getPoint(), INT_MAX));
        prev.insert(std::pair<std::string, std::string>(v.getPoint(), ""));
    }
    dist[startpath] = 0;                                                                                //start off at value 0 for distance travelled

    std::vector<std::string> S;                                                                         //vector string S
    typedef std::pair<unsigned long, std::string> pi;                                                   //build priority queue to hold pair of vertex and adjacent path and vertices 
    std::priority_queue<pi, std::vector<pi>, std::greater<pi>> Q;                                       //... to push in an ordered path that directs to shortest path 
    for(auto d : dist){
        Q.push(std::make_pair(d.second, d.first));
    }

    while(!Q.empty()){                                                                                  //Dijkstra's Algorithm while loop when the priority queue is not empty to store
        pi uUtil = Q.top();
        std::string U = uUtil.second;
        Q.pop();
        S.push_back(U);
        for(std::vector<Vertex>::iterator it = std::begin(vertices); it != std::end(vertices); ++it){
            if(it->getPoint() == U){                                                                    // locate the U vertex
                for(auto edge : it->getEdgeMap()){                                                      // loop through every edge
                    if(dist[edge.first] > dist[U] + edge.second){
                        dist[edge.first] = dist[U] + edge.second;
                        Q = std::priority_queue<pi, std::vector<pi>, std::greater<pi>>();               // update the priorty queue
                        for(auto v : dist){
                            Q.push(std::make_pair(v.second, v.first));
                        }
                        prev[edge.first] = U; // set parent of the edge in the parent map
                    }
                }
                break;
            }
        }
    }
    path = getPath(endpath, prev, path);   //initialize path veriable with the main shortest path
    return dist[endpath];
}//end shortestPath (Dijkstra's Algorithm)