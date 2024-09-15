# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezeper <ezeper@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 17:10:31 by ezeper            #+#    #+#              #
#    Updated: 2024/04/11 16:45:28 by ezeper           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.SILENT:
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRCS = ft_printf.c ft_print_char.c ft_print_dig.c ft_print_hex.c ft_print_pointer.c ft_print_unsgn.c ft_print_str.c 

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT)
	echo "Printf Compiled"

# $(NAME): $(OBJS)
# 		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
	echo "Object Files are deleted"

fclean: clean
	rm -rf $(NAME)
	echo "Everything is clean"

re: fclean all

.PHONY: all clean fclean re
