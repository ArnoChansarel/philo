# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achansar <achansar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:37:55 by achansar          #+#    #+#              #
#    Updated: 2023/03/27 18:20:05 by achansar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TARGET
NAME = philo

#ARGUMENTS
CC = gcc
FLAGS = -Wall -Werror -Wextra -pthread
SEG = #-fsanitize=address -g
SEGT = -fsanitize=thread

#PHILO FILES
SRC_PATH = ./srcs/
SRC =	philo \
		routine \
		threads_mutexes \
		init \
		monitoring \
		utils
C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c))
OBJ = $(addprefix $(SRC_PATH), $(SRC:=.o))

#LIBFT
LBFT_PATH = ./libft/
LBFT = 	list \
		ft_atoi
LBFT_FILES = $(addprefix $(LBFT_PATH), $(LBFT:=.c))
LBFT_OBJ = $(addprefix $(LBFT_PATH), $(LBFT:=.o))

#RULES
all: $(NAME)

$(NAME): $(OBJ) $(LBFT_OBJ)
	@ $(CC) $(FLAGS) $(SEG) $(SEGT) $(OBJ) $(LBFT_OBJ) -o $(NAME)

.c.o:
	@ $(CC) $(FLAGS) $(SEG) $(SEGT) -c $< -o $@

clean:
	@rm -f $(OBJ) $(LBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re