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

  void generate_edges(unsigned edges_num);

  const std::vector<EdgeId>& get_connected_edge_ids(VertexId vertex_id) const {
    return adjacency_.at(vertex_id);
  }

  const std::unordered_map<EdgeId, Edge>& get_edges() const { return edges_; }

  const std::unordered_map<VertexId, Vertex>& get_vertices() const {
    return vertices_;
  }

  void set_max_weight(Weight val) { MaxWeight = val; }

  void set_min_weight(Weight val) { MinWeight = val; }

  friend void bell_ford_bypass(Graph& graph, VertexId src,
                               std::unordered_map<VertexId, Weight>& dist);

  friend void dijkstra_bypass(Graph& graph, VertexId src,
                              std::unordered_map<VertexId, Weight>& dist);

 private:
  VertexId last_vertex_id_ = 0;
  EdgeId last_edge_id_ = 0;

  std::unordered_map<VertexId, Vertex> vertices_;
  std::unordered_map<EdgeId, Edge> edges_;
  std::unordered_map<VertexId, std::vector<EdgeId>> adjacency_;
};