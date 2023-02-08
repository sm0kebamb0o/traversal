#include <sstream>
#include <string>
#include <unordered_map>

#include "graph_json_printing.hpp"

namespace printing {
namespace json {
std::string print_vertex(const Vertex& vertex, const Graph& graph) {
  std::stringstream json_string;
  json_string << "\n\t\t{ \"id\":" << vertex.id() << ", \"edge_ids\": [";
  const auto& edge_ids = graph.get_connected_edge_ids(vertex.id());

  if (!edge_ids.empty()) {
    bool is_first_iteration = true;
    for (auto it = edge_ids.cbegin(); it != edge_ids.cend(); ++it) {
      if (!is_first_iteration){
        json_string << ", ";
      }
      json_string << *it;
      is_first_iteration = false;
    }
  }
  json_string << "] }";

  return json_string.str();
}

std::string print_edge(const Edge& edge, const Graph& graph) {
  std::stringstream json_string;
  json_string << "\n\t\t{ \"id\": " << edge.id() << ", \"vertex_ids\": ["
              << edge.from() << ", "
              << edge.to() << "] }";

  return json_string.str();
}

std::string print_graph(const Graph& graph) {
  std::stringstream json_string;
  json_string << "{\n\t\"vertices\": [";
  const auto& vertices = graph.get_vertices();
  const auto& edges = graph.get_edges();

  if (!vertices.empty()) {
    bool is_first_iteration = true;
    for (auto it = vertices.cbegin(); it != vertices.cend(); ++it) {
      if (!is_first_iteration) {
        json_string << ",";
      }
      json_string << print_vertex(it->second, graph);
      is_first_iteration = false;
    }
  }
  json_string << "\n\t],\n\t\"edges\": [";

  if (!edges.empty()) {
    bool is_first_iteration = true;

    for (auto it_edges = edges.cbegin(); it_edges != edges.cend(); ++it_edges) {
      if (!is_first_iteration) {
        json_string << ",";
      }
      json_string << print_edge(it_edges->second, graph);
      is_first_iteration = false;
    }
  }
  json_string << "\n\t]\n}\n";
  return json_string.str();
}
}  // namespace json
}  // namespace printing