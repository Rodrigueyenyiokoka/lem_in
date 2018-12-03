# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyenyi- <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/21 12:53:47 by oyenyi-           #+#    #+#              #
#    Updated: 2018/09/22 14:41:39 by oyenyi-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= lem_in

RCS			= ./resources

SRCS		= ./srcs/*.c

LIBFT		= ./libft

INCLUDES	= ./includes

FLAGS = -Wextra -Werror -Wall  -I./includes

CC = gcc

all: $(NAME)
$(NAME):
	@$(MAKE) -C $(LIBFT) all
	@$(CC) -o $(NAME) $(FLAGS) $(SRCS) libft/libft.a
	@echo "\x1B[32mLem_in compiled successfully\x1B[3m"
	clear

clean:
	@make clean -C libft
fclean:
	@make fclean -C libft
	@rm -f $(NAME)

re:	fclean all
