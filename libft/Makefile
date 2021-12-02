# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 18:00:35 by ialvarez          #+#    #+#              #
#    Updated: 2021/09/13 17:32:21 by ialvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS	= ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strlcat.c ft_atoi.c \
		ft_isalpha.c ft_memccpy.c ft_memmove.c ft_strlcpy.c ft_strrchr.c \
	   	ft_bzero.c ft_isascii.c ft_memchr.c ft_memset.c ft_strlen.c \
		ft_tolower.c ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strncmp.c \
		ft_toupper.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c \
	   	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_itoa_base.c ft_itoa_base_x.c

SRCSBN	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

OBJSBN	= ${SRCSBN:.c=.o}
OBJS	= ${SRCS:.c=.o}

${NAME}:	${SRCS}
			${GCC} -c ${CFLAGS} ${SRCS}
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSBN}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}

bonus:		${NAME}
			${GCC} -c ${CFLAGS} ${SRCSBN}
			ar -rcs ${NAME} ${OBJSBN}

.PHONY:
			clean
			fclean
			all
			re
			bonus
