# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 16:24:53 by thbernar          #+#    #+#              #
#    Updated: 2017/12/04 20:06:37 by thbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = backtracking.c \
	  check.c \
	  main.c \
	  functions.c \
	  other_functions.c

OBJ = backtracking.o\
	  check.o\
	  main.o\
	  functions.o\
	  other_functions.o

HEADER = fillit.h

CPPFLAGS = -I.

LIBFLAGS = -Llibft -lft

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIBFT = ./libft/libft.a

LIBFT_DIR = ./libft/

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBFT_DIR)


$(NAME): $(HEADER) $(OBJ) $(LIBFT)
	$(CC) -c $(SRC) $(CPPFLAGS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
