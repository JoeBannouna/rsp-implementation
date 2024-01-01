#include <iostream>

#include "Graph.hpp"

using std::cout;
using std::endl;

void printVertex(Vertex ver) { cout << ver.index << ", "; }

int main() {
  Graph* graph = new Graph();

  Vertex* vertex0 = graph->addVertex(12);
  Vertex* vertex1 = graph->addVertex(13);
  Vertex* vertex2 = graph->addVertex(14);
  Vertex* vertex3 = graph->addVertex(15);
  Vertex* vertex4 = graph->addVertex(16);

  graph->addEdge(2, 4);
  graph->addEdge(0, 4);
  graph->addEdge(1, 4);
  graph->addEdge(1, 3);
  graph->addEdge(1, 3);

  // graph->delEdge(1, 3);

  graph->printGraph();

  cout << "Degree: " << graph->getVertexDegree(1) << endl;

  cout << "BFS Search:" << endl;
  graph->bfs(printVertex);
  cout << endl;

  cout << "DFS Search:" << endl;
  graph->dfs(printVertex);
  cout << endl;

  // Node* node1 = tree->insert(10);
  // Node* node2 = tree->insert(12);
  // Node* node3 = tree->insert(9);
  // Node* node4 = tree->insert(15);
  // Node* node5 = tree->insert(7);
  // Node* node6 = tree->insert(4);
  // Node* node7 = tree->insert(13);
  // Node* node8 = tree->insert(29);
  // Node* node9 = tree->insert(18);
  // Node* node10 = tree->insert(31);
  // Node* node11 = tree->insert(19);
  // Node* node12 = tree->insert(16);
  // Node* node13 = tree->insert(20);
  // Node* node14 = tree->insert(11);
  // Node* node15 = tree->insert(33);

  // printTree(tree);

  // cout << "Tree min: " << (tree->findMin() == NULL ? INT32_MIN : tree->findMin()->getItem()) << endl;
  // cout << "Tree min: " << (tree->findMax() == NULL ? INT32_MAX : tree->findMax()->getItem()) << endl;

  // tree->del(node1);
  // printTree(tree);

  // tree->del(node6);
  // printTree(tree);

  // Node* search_node;

  // search_node = tree->search(10);
  // cout << "Node " << (search_node == NULL ? "not" : std::to_string(search_node->getItem())) << " found" << endl;

  // search_node = tree->search(11);
  // cout << "Node " << (search_node == NULL ? "not" : std::to_string(search_node->getItem())) << " found" << endl;
}