CC = clang++
INT = interfaces/i_edge.hpp interfaces/i_vertex.hpp interfaces/i_graph.hpp
STR = structures/vertex.hpp structures/edge.hpp

style:
	clang-format -i -style=Google $(INT)