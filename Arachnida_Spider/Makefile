NAME = spider

CPP = c++

42CPP = g++

FLAGS = -g -Wall -Wextra -Werror

SRCS = \
spider.cpp

OBJS = ${SRCS:.cpp=.o}

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

URL = https://www1.folha.uol.com.br/poder/2026/10/area-tecnica-do-tse-diz-a-kassio-nao-ter-achado-conteudo-citado-por-flavio-em-canal-de-janones.shtml

ARGS = -rlp 5 ./imgs/
# ARGS =

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)
	clear

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME) $(ARGS) $(URL)

val: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS) $(URL)

tests: re
	./$(NAME) $(ARGS) $(URL)
