#include <iostream>

#include "structures/graph.hpp"

template <class Key, class Arg>
std::ostream& operator<<(std::ostream& out, std::unordered_map<Key, Arg>& arg) {
  for (auto& el : arg) {
    out << el.first << " " << el.second << "\n";
  }
  return out;
}

int main() {
  Graph graph;
  graph.generate_vertices(10);
  graph.print_vertices();
  std::cout << std::endl;

  graph.generate_edges(24);

  graph.print_edges();

  std::cout << std::endl;

  std::unordered_map<VertexId, Weight> dist_1, dist_2;
  bell_ford(graph, 0, dist_1);

  std::cout << dist_1;

  std::cout << std::endl;

  dijkstra(graph, 0, dist_2);
  std::cout << dist_2;
}