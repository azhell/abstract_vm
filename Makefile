# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalytvyn <yalytvyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 10:49:31 by yalytvyn          #+#    #+#              #
#    Updated: 2019/10/17 11:21:02 by yalytvyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= avm

SRC		= src/main.cpp \

OBJ		= $(patsubst src/%.cpp,obj/%.o,$(SRC))

FLAG	= -Wall -Wextra -Werror -Iinc

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)

	clang++ $(SRC) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create $(NAME)"

obj/%.o: src/%.cpp
	mkdir -p obj
	clang++ $(FLAG) -c $< -o $@ -Iinc
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean all