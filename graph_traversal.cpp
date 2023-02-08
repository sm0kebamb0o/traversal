#include "structures/graph.hpp"

void bell_ford(Graph& graph, VertexId src,
               std::unordered_map<VertexId, Weight>& dist) {
  constexpr unsigned INF = std::numeric_limits<Weight>::max();

  for (auto& edge : graph.edges_) {
    dist[edge.second.from()] = INF;
    dist[edge.second.to()] = INF;
  }
  dist[src] = 0;

  auto temp = dist;
  for (unsigned i = 0; i < graph.vertices_.size() - 1; ++i) {
    temp = dist;
    for (auto& edge : graph.edges_) {
      if (dist[edge.second.from()] != INF) {
        temp[edge.second.to()] =
            std::min(temp[edge.second.to()],
                     dist[edge.second.from()] + edge.second.cost());
      }
    }
    dist = temp;
  }
}