NAME = GraphTest.o

SRC =	BreadthFirstSearch.cpp \
	DepthFirstSearch.cpp \
	GraphAdjacentList.cpp \
	main.cpp

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	g++ $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re:	clean all
