# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/16 12:48:23 by clorin            #+#    #+#              #
#    Updated: 2020/10/16 12:48:27 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##gcc -Werror -Wextra -Wall main.c -o reseaux -L. -lft -L. -lftprintf

NAME = reseaux

#	Sources

SRC			=	main.c

CC			=	gcc

FLAGS		= -Werror -Wextra -Wall

all : $(NAME)


$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) -L. -lft -L. -lftprintf

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
