# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 10:38:56 by jdesmare          #+#    #+#              #
#*   Updated: 2017/02/13 11:19:08 by jdesmare         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc $(FLAGS)

FLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes/

SRC =	main.c							\
		hash.c							\
		get_stdin.c						\
		get_infos.c						\
		get_infos.c						\
		get_tube.c						\
		ft_new_hashlist.c				\
		algo.c							\
		bfs_tools.c						\
		move_ants.c						\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(CC) -I$(INCLUDES) -c $(SRC)
	@$(CC) $^ -L./libft/ -lft -o $@
	@echo "$(NAME) created successfully"

%.o: %.c
	@$(CC) -I$(INCLUDES) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "Erasing .o files in Lem_in..."
	@rm -f $(OBJ)
	@echo "Done."

fclean: clean
	@make fclean -C ./libft/
	@echo "Erasing $(NAME)..."
	@rm -f $(NAME)
	@echo "Done."

re: fclean all clean

.PHONY: all, clean, fclean, re
