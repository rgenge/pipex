# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acosta-a <acosta-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 02:03:37 by acosta-a          #+#    #+#              #
#    Updated: 2022/07/10 15:25:34 by acosta-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# Compilation #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
OPTCC=  -I. -c
RM = rm -rf

#HEADER = /include#
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
# SOURCE FILES #
SRC = ./src/pipex.c ./src/utils.c ./src/parse.c
BONUS = ./bonus/bonus.c ./bonus/utils.c ./bonus/parse.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

SRC.O = $(SRC:%.c=%.o)
BONUS.O = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRC.O)
	$(RM) $(NAME)
	make -C ${LIBFT_PATH}
	$(CC) $(CFLAGS) $(SRC.O) $(LIBFT) -o $(NAME)

bonus: $(NAME)_bonus

$(NAME)_bonus :	$(BONUS.O)
	$(CC) $(CFLAGS) $(BONUS.O) $(LIBFT) -o $(NAME)_bonus

clean:
	$(RM) $(SRC.O)
	$(RM) $(BONUS.O)
	make clean -C ${LIBFT_PATH}
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)_bonus
	make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: clean fclean bonus re
