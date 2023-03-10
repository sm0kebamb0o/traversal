#include <fstream>
#include <iostream>

#include "printing/graph_json_printing.hpp"
#include "structures/graph.hpp"

template <class Key, class Arg>
std::ostream& operator<<(std::ostream& out, std::unordered_map<Key, Arg>& arg) {
  for (auto& el : arg) {
    out << el.first << " " << el.second << "\n";
  }
  return out;
}

void write_to_file(const std::string& graph_str, const std::string& file_name) {
  std::ofstream fout(file_name);
  fout << graph_str;
}

int main(int argc, char* argv[]) {
  Graph graph;
  graph.generate_vertices(atoi(argv[1]));
  graph.generate_edges(atoi(argv[2]));

  std::unordered_map<VertexId, Weight> dist_1, dist_2;
  bell_ford_bypass(graph, 0, dist_1);

  std::cout << dist_1;

  std::cout << std::endl;

  dijkstra_bypass(graph, 0, dist_2);
  std::cout << dist_2;

  const auto out = printing::json::print_graph(graph);
  write_to_file(out, "graph.json");
}