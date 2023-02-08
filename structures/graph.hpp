#pragma once

#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

#include "../interfaces/i_graph.hpp"
#include "edge.hpp"
#include "vertex.hpp"

namespace {
Weight MinWeight = 0;
Weight MaxWeight = 20;
constexpr unsigned INF = std::numeric_limits<Weight>::max();
};  // namespace

class Graph : public iGraph {
 public:
  void add_vertex(VertexId id = notPossibleId) override;

  void add_edge(VertexId from, VertexId to, Weight cost,
                EdgeId id = notPossibleId) override;

  void generate_vertices(unsigned vertices_num) override;

  void print_vertices() const override;

  void generate_edges(unsigned edges_num);

  void print_edges() const;

  void set_max_weight(Weight val) { MaxWeight = val; }

  void set_min_weight(Weight val) { MinWeight = val; }

  friend void bell_ford(Graph& graph, VertexId src,
                        std::unordered_map<VertexId, Weight>& dist);

  friend void dijkstra(Graph& graph, VertexId src,
                       std::unordered_map<VertexId, Weight>& dist);

 private:
  VertexId last_vertex_id_ = 0;
  EdgeId last_edge_id_ = 0;

  std::unordered_map<VertexId, Vertex> vertices_;
  std::unordered_map<EdgeId, Edge> edges_;
  std::unordered_map<VertexId, std::vector<EdgeId>> adjacency_;
};