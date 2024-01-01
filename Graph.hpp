#pragma once

#include <queue>
#include <vector>

#include "LinkedList.hpp"

using std::queue;
using std::vector;

enum State { Undiscovered, Discovered, Processed };

struct Vertex {
  int index;
  int value;
  LinkedList* edges;
};

class Graph {
 private:
  vector<Vertex> adjancency_list;
  int vertices_num;
  int edges_num;

 protected:
  void dfs(void (*process)(Vertex ver), Vertex u, vector<State>);

 public:
  Graph();

  Vertex* addVertex(int value);

  void addEdge(int vertex_x, int vertex_y);
  void addEdge(Vertex* vertex_x, Vertex* vertex_y);

  void delEdge(int vertex_x, int vertex_y);

  int getVertexDegree(int vertex);

  bool edgeExists(int vertex_x, int vertex_y);
  bool edgeExists(Vertex* vertex_x, Vertex* vertex_y);

  void printGraph();

  void bfs(void (*process)(Vertex ver));

  void dfs(void (*process)(Vertex ver));
};