#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../interfaces/i_graph.hpp"
#include "edge.hpp"
#include "vertex.hpp"

class Graph : public iGraph {
 public:
  void add_vertex(VertexId id = notPossibleId) override;

  void add_edge(VertexId from, VertexId to, Weight cost,
                EdgeId id = notPossibleId) override;

  void generate_vertices(unsigned vertices_num) override;

  void print_vertices() const override;

  void generate_edges(unsigned edges_num);

  void print_edges() const;

  Weight find_cost(EdgeId id) override;

  friend void bell_ford(Graph& graph, VertexId src,
                        std::unordered_map<VertexId, Weight>& dist);

 private:
  VertexId last_vertex_id_ = 0;
  EdgeId last_edge_id_ = 0;

  std::unordered_map<VertexId, Vertex> vertices_;
  std::unordered_map<EdgeId, Edge> edges_;
  std::unordered_map<VertexId, EdgeId> adjacency_;
};