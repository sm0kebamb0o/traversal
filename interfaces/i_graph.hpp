#pragma once

#include "i_edge.hpp"
#include "i_vertex.hpp"

class iGraph {
public:
  virtual ~iGraph(){}
  virtual void add_vertex(VertexId id = notPossibleId) = 0;

  virtual void add_edge(VertexId from, VertexId to, Weight cost,
                EdgeId id = notPossibleId) = 0;

  virtual void generate_vertices(unsigned vertices_num) = 0;

  virtual void print_vertices() const = 0;
};