#include "graph.hpp"

#include <iostream>

void Graph::add_vertex(VertexId id = notPossibleId) {
  if (vertices_.find(id) != vertices_.end()) {
    std::cerr << "The required vertex id has been already used!" << std::endl
              << "New vertex id is " << last_vertex_id_ << "." << std::endl;
    id = notPossibleId;
  }

  if (id == notPossibleId) id = last_vertex_id_++;
  vertices_[id] = Vertex(id);

  if (last_vertex_id_ == notPossibleId) {
    std::cerr << "No more vertex id's left!" << std::endl;
  }
}

void Graph::add_edge(VertexId from, VertexId to, Weight cost, EdgeId id = notPossibleId){
    if (edges_.find(id) != edges_.end()){
      std::cerr << "The required edge id has been already used!" << std::endl
                << "New edge id is " << last_edge_id_ << "." << std::endl;
      id = notPossibleId;
    }

    if (id == notPossibleId) id = last_edge_id_++;
    edges_[id] = Edge(id, from, to, cost);

    adjacency_[from][id] = cost;

    if (last_edge_id_ == notPossibleId){
      std::cerr << "No more edge id's left!" << std::endl;
    }
}

Weight Graph::find_cost(EdgeId id){
    return edges_.at(id).cost();
}