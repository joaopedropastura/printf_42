# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 10:54:01 by jpedro-s          #+#    #+#              #
#    Updated: 2021/11/29 14:33:39 by jpedro-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_types.c

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

RM = rm -rf

LIBFT = ./libft

.c.o:

			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C libft
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

re: fclean all

clean:

	$(RM) $(OBJS)

fclean: clean

	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

.PHONY: all re clean fclean out
