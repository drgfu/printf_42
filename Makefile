# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkais <kkais@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 14:15:44 by kkais             #+#    #+#              #
#    Updated: 2021/12/16 18:06:19 by kkais            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c libft_utils.c
OBJECTS = $(SOURCES:.c=.o)
LIBFT_OBJECTS = libft/*.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJECTS) libft
	$(AR) -r $@ $(OBJECTS) $(LIBFT_OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re