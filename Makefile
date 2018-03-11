# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/10 17:40:03 by alischyn          #+#    #+#              #
#    Updated: 2017/12/10 17:40:04 by alischyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -g
SOURCES = main.c \
		  get_next_line.c \
		  hashmap.c \
		  hashmap_alloc.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_strncat.c \
		  ft_strchr.c  \
		  ft_bzero.c \
		  ft_strlen.c \

OBJECTS = $(SOURCES:.c=.o)
NAME = hotrace

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(OBJECTS) $(NAME)

re: fclean all

norm:
	norminette $(SOURCES) $(wildcard *.h)
