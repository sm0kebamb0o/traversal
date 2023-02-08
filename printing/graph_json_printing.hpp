#pragma once

#include <string>

#include "../structures/graph.hpp"

namespace printing {
namespace json {
std::string print_vertex(const Vertex& vertex, const Graph& graph);
std::string print_edge(const Edge& edge, const Graph& graph);
std::string print_graph(const Graph& graph);
}  // namespace json
}  // namespace printing