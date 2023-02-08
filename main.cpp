#include <iostream>

#include "structures/graph.hpp"

int main() {
  Graph graph;
  graph.generate_vertices(10);
  graph.print_vertices();
  std::cout << std::endl;

  graph.generate_edges(24);

  graph.print_edges();

  std::cout << std::endl;

  std::unordered_map<VertexId, Weight> dist;
  bell_ford(graph, 0, dist);

  for (auto& el : dist) {
    std::cout << el.first << " " << el.second << "\n";
  }
}