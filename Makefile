# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 19:34:17 by ialvarez          #+#    #+#              #
#    Updated: 2021/12/13 16:18:34 by ialvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap

SRCS = push_swap.c no_repeat.c 

OBJECTS = $(SRCS:.c=.o)
LIBFT_DIR = libft/
LIB_NAME = $(LIBFT_DIR)libft.a
INCLUDES = -I. -I$(LIBFT_DIR)
FSANITIZE = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $^ -L ./libft/ -l ft -o $(NAME)

debug: $(OBJECTS)
	@make -s -C $(LIBFT_DIR) 
	@$(CC) $(CFLAGS) $(FSANITIZE) $^ -L ./libft/ -l ft -o $(NAME)
	
clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJECTS)

normi:
	norminette $(SRCS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY:
			clean
			fclean
			all
			re
			bonus
