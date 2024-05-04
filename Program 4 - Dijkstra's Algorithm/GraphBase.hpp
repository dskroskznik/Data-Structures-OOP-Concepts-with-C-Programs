#ifndef GRAPHBASE_H
#define GRAPHBASE_H

#include <vector>
#include <string>

class GraphBase
{
  virtual void addVertex(std::string point) = 0;
  virtual void removeVertex(std::string point) = 0;
  virtual void addEdge(std::string point_a, std::string point_b, unsigned long weight) = 0;
  virtual void removeEdge(std::string point_a, std::string point_b) = 0;
  virtual unsigned long shortestPath(std::string startpath, std::string endpath, std::vector<std::string> &path) = 0;
};

#endif