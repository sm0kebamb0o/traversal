using VertexId = unsigned;

constexpr VertexId notPossibleId = ~0;

class iVertex {
 public:
  virtual VertexId id() const = 0;
};
