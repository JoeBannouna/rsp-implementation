#include "Graph.hpp"

Graph::Graph() {
  this->vertices_num = 0;
  this->edges_num = 0;
}

Vertex* Graph::addVertex(int value) {
  Vertex new_vertex;
  new_vertex.value = value;
  new_vertex.index = this->vertices_num;
  new_vertex.edges = new LinkedList();
  this->adjancency_list.push_back(new_vertex);

  this->vertices_num++;

  return &adjancency_list.at(adjancency_list.size() - 1);
}

void Graph::addEdge(int vertex_x, int vertex_y) {
  if (vertex_x != vertex_y && !edgeExists(vertex_x, vertex_y)) {
    this->adjancency_list[vertex_x].edges->insert(vertex_y);
    this->adjancency_list[vertex_y].edges->insert(vertex_x);

    this->edges_num++;
  }
}

void Graph::addEdge(Vertex* vertex_x, Vertex* vertex_y) {
  if (vertex_x != vertex_y && !edgeExists(vertex_x, vertex_y)) {
    this->adjancency_list[vertex_x->value].edges->insert(vertex_y->value);
    this->adjancency_list[vertex_y->value].edges->insert(vertex_x->value);

    this->edges_num++;
  }
}

void Graph::delEdge(int vertex_x, int vertex_y) {
  this->adjancency_list[vertex_x].edges->del(vertex_y);
  this->adjancency_list[vertex_y].edges->del(vertex_x);

  this->edges_num++;
}

int Graph::getVertexDegree(int vertex) { return this->adjancency_list[vertex].edges->length(); }

bool Graph::edgeExists(int vertex_x, int vertex_y) {
  if (this->adjancency_list[vertex_x].edges->search(vertex_y) != NULL) return true;
  return false;
}

bool Graph::edgeExists(Vertex* vertex_x, Vertex* vertex_y) {
  if (vertex_x->edges->search(vertex_y->value) != NULL) return true;
  return false;
}

void Graph::printGraph() {
  int i = 0;
  for (Vertex vertex : this->adjancency_list) {
    cout << i << ": " << vertex.value << " -> ";
    vertex.edges->printList();
    i++;
  }
}

void Graph::bfs(void (*process)(Vertex ver)) {
  int* p = new int[vertices_num];
  vector<Vertex> vertices = this->adjancency_list;
  vector<State> vertices_states;
  for (int i = 0; i < vertices.size(); i++) vertices_states.push_back(Undiscovered);

  Vertex vertex1 = vertices[0];
  vertices_states[0] = Discovered;
  p[0] = INT32_MAX;

  queue<Vertex> vertex_queue;
  vertex_queue.push(vertex1);

  while (!vertex_queue.empty()) {
    Vertex u = vertex_queue.front();
    vertex_queue.pop();

    process(u);

    LinkedList* curr = u.edges->getNext();

    while (curr != NULL) {
      if (vertices_states[curr->getItem()] == Undiscovered) {
        vertices_states[curr->getItem()] = Discovered;
        p[curr->getItem()] = u.index;
        vertex_queue.push(vertices[curr->getItem()]);
      }

      curr = curr->getNext();
    }

    vertices_states[u.index] = Processed;
  }
}

void Graph::dfs(void (*process)(Vertex ver)) {
  vector<State> vertices_states;
  for (int i = 0; i < this->adjancency_list.size(); i++) vertices_states.push_back(Undiscovered);
  this->dfs(process, this->adjancency_list[0], vertices_states);
}

void Graph::dfs(void (*process)(Vertex ver), Vertex u, vector<State> vertices_states) {
  LinkedList* curr = u.edges->getNext();

  if (vertices_states[u.index] != Discovered) {
    vertices_states[u.index] = Discovered;

    process(u);

    while (curr != NULL) {
      this->dfs(process, this->adjancency_list[curr->getItem()], vertices_states);
      curr = curr->getNext();
    }

    vertices_states[u.index] = Processed;
  }
}