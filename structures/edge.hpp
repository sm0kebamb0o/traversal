#include <interfaces/i_edge.hpp>

class Edge : public iEdge {
 public:
  Edge(EdgeId id, VertexId from, VertexId to, Weight cost)
      : id_(id), from_(from), to_(to), cost_(cost) {}

  EdgeId id() const override { return id_; }

  VertexId from() const override { return from_; }

  VertexId to() const override { return to_; }

  Weight cost() const override { return cost_; }
 private:
  EdgeId id_;
  VertexId from_;
  VertexId to_;
  Weight cost_; 
};