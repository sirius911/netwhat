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

SRC			=	src/main.c \
				src/ft_power.c src/ft_functions.c src/ft_lst.c src/ft_cidr.c

CC			=	gcc

FLAGS		= -Werror -Wextra -Wall

HEADER		= -I includes/

OBJ 		= $(SRC:.c=.o)

all : $(NAME)

.c.o:
			@${CC} ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}
			@echo "compilation : "$< "\033[32mok\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(HEADER) $(OBJ) -o $(NAME) -L. -lft -L. -lftprintf
	@echo "création de reseaux : \033[32mok\033[0m"

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
