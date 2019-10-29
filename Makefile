# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 10:49:31 by yalytvyn          #+#    #+#              #
#    Updated: 2019/10/21 19:01:50 by yalytvyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= avm

SRC		=   src/main.cpp \
			src/Factory.cpp \
			src/Flex.cpp \
			src/flexLexer.cpp

OBJ		= $(patsubst src/%.cpp,obj/%.o,$(SRC))

FLAG	= -Wall -Wextra -Wunused-parameter#-Werror

INC		= -Iinc

.SILENT:

all: flex $(NAME)

$(NAME): $(OBJ)
	clang++ $(SRC) -o $(NAME) $(INC)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create $(NAME)"

obj/%.o: src/%.cpp
	mkdir -p obj
	clang++ $(FLAG) -c $< -o $@ $(INC)
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

flex:
	flex -o src/flexLexer.cpp -c++ src/flexLexer.l
clean:
	rm -rf src/flexLexer.cpp
	/bin/rm -rf obj/
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean all