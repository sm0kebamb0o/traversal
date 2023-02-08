#pragma once

#include "i_vertex.hpp"
#include <limits>

using EdgeId = unsigned;
using Weight = unsigned;

constexpr Weight MinWeight = 0;
constexpr Weight MaxWeight = 20;

class iEdge {
 public:
  virtual ~iEdge(){};
  virtual EdgeId id() const = 0;
  virtual VertexId from() const = 0;
  virtual VertexId to() const = 0;
  virtual Weight cost() const = 0;
};
