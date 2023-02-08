#include <queue>

#include "structures/graph.hpp"

void bell_ford(Graph& graph, VertexId src,
               std::unordered_map<VertexId, Weight>& dist) {
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

void dijkstra(Graph& graph, VertexId src,
              std::unordered_map<VertexId, Weight>& dist) {
  using ToCost = std::pair<Weight, VertexId>;
  std::priority_queue<ToCost, std::vector<ToCost>, std::greater<ToCost>> pq;
  Weight cur_cost;
  VertexId cur_vert;

  for (auto& edge : graph.edges_) {
    dist[edge.second.from()] = INF;
    dist[edge.second.to()] = INF;
  }
  dist[src] = 0;

  pq.push({0, src});

  while (!pq.empty()) {
    std::tie(cur_cost, cur_vert) = pq.top();
    pq.pop();

    if (cur_cost > dist[cur_vert]) continue;

    for (auto edge_id : graph.adjacency_[cur_vert]) {
      auto cur_edge = graph.edges_.at(edge_id);
      if (dist[cur_vert] + cur_edge.cost() < dist[cur_edge.to()]) {
        dist[cur_edge.to()] = dist[cur_vert] + cur_edge.cost();
        pq.push({dist[cur_edge.to()], cur_edge.to()});
      }
    }
  }
}