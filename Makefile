CC = clang++
INT = interfaces/i_edge.hpp interfaces/i_vertex.hpp interfaces/i_graph.hpp
STR_HPP = structures/vertex.hpp structures/edge.hpp structures/graph.hpp 
STR_CPP = structures/graph.cpp
TRAV = graph_traversal.cpp
MAIN = main.cpp
ALL_SRC = $(STR_CPP) $(MAIN) $(TRAV)
ALL_OBJ = ${ALL_SRC:cpp=o}
ALL = $(ALL_SRC) $(STR_HPP)
RES = main
LOG = log.txt

all: $(ALL_SRC)
	$(CC) $(ALL_SRC) -o $(RES)

%.o : %.cpp
	$(CC) -c $<

run : $(RES)
	./$(RES) 2> $(LOG)

style:
	clang-format -i -style=Google $(ALL)

clean:
	rm -rf $(RES) $(LOG)