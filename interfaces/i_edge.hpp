#include "i_vertex.hpp"

using EdgeId = unsigned;
using Weight = unsigned;

class iEdge {
 public:
  virtual EdgeId id() const = 0;
  virtual VertexId from() const = 0;
  virtual VertexId to() const = 0;
  virtual Weight cost() const = 0;
};
