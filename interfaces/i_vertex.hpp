#pragma once

using VertexId = unsigned;

constexpr VertexId notPossibleId = ~0;

class iVertex {
 public:
  virtual ~iVertex(){}
  virtual VertexId id() const = 0;
};
