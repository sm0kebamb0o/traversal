#include "graph.hpp"

#include <iostream>
#include <random>

void Graph::add_vertex(VertexId id) {
  static bool aval_vertices = true;

  if (!aval_vertices) {
    std::cerr << "There is no space for new vertex!" << std::endl;
    std::runtime_error("There is no space for new vertex!");
  }

  if (vertices_.find(id) != vertices_.end()) {
    std::cerr << "The required vertex id has been already used!" << std::endl
              << "New vertex id is " << last_vertex_id_ << "." << std::endl;
    id = notPossibleId;
  }

  if (id == notPossibleId) id = last_vertex_id_++;
  vertices_.insert({id, Vertex(id)});

  if (last_vertex_id_ == notPossibleId) {
    std::cerr << "No more vertex id's left!" << std::endl;
  }
}

void Graph::add_edge(VertexId from, VertexId to, Weight cost, EdgeId id) {
  static bool aval_edges = true;

  if (!aval_edges) {
    std::cerr << "There is no space for new edge!" << std::endl;
    std::runtime_error("There is no space for new edge!");
  }

  if (vertices_.find(from) == vertices_.end() ||
      vertices_.find(to) == vertices_.end()) {
    std::cerr << "The specified verticies do not exist!" << std::endl;
    std::runtime_error("The specified verticies do not exist!");
  }

  if (edges_.find(id) != edges_.end()) {
    std::cerr << "The required edge id has been already used!" << std::endl
              << "New edge id is " << last_edge_id_ << "." << std::endl;
    id = notPossibleId;
  }

  if (id == notPossibleId) id = last_edge_id_++;
  edges_.insert({id, Edge(id, from, to, cost)});

  adjacency_[from].push_back(id);

  if (last_edge_id_ == notPossibleId) {
    std::cerr << "No more edge id's left!" << std::endl;
    aval_edges = false;
  }
}

void Graph::generate_vertices(unsigned vertices_num) {
  while (vertices_num--) {
    add_vertex();
  }
}

void Graph::print_vertices() const {
  for (auto& vertex : vertices_) {
    std::cout << vertex.first << " ";
  }
  std::cout << std::endl;
}

void Graph::generate_edges(unsigned edges_num) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib_vertex(0, vertices_.size() - 1);
  std::uniform_int_distribution<> distrib_cost(MinWeight, MaxWeight);

  for (int id = 0; id < edges_num; ++id) {
    auto first = distrib_vertex(gen), second = distrib_vertex(gen);
    auto weigh = distrib_cost(gen);
    add_edge(first, second, weigh, id);
  }
}

void Graph::print_edges() const {
  for (auto& edge : edges_) {
    std::cout << edge.second.from() << " " << edge.second.to() << " "
              << edge.second.cost() << std::endl;
  }
}