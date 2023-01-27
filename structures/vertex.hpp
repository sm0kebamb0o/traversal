#include <interfaces/i_vertex.hpp>

class Vertex : public iVertex{
public:
  explicit Vertex(VertexId id) : id_(id) {}

  VertexId id() const override { return id_; }
private:
  VertexId id_;
};