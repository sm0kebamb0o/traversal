#include <interfaces/i_graph.hpp>
#include "edge.hpp"
#include "vertex.hpp"

#include <vector>
#include <unordered_map>
#include <iostream>

class Graph : public iGraph{
public:
  void add_vertex(VertexId id = notPossibleId);

  void add_edge(VertexId from, VertexId to, Weight cost, EdgeId id = notPossibleId);

  Weight find_cost(EdgeId id);
private:
  VertexId last_vertex_id_ = 0;
  EdgeId last_edge_id_ = 0;

  std::unordered_map<VertexId, Vertex> vertices_;
  std::unordered_map<EdgeId, Edge> edges_;
  std::unordered_map<VertexId, std::unordered_map<EdgeId, Weight>> adjacency_;
};