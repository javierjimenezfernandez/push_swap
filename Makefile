# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 23:21:14 by javjimen          #+#    #+#              #
#    Updated: 2024/03/07 17:39:51 by javjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME		= push_swap

# Dependancies
LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

# List of source files
SRC_DIR		= src/
SRC			= $(addprefix $(SRC_DIR), push_swap.c \
									  stack_utils.c \
									  split_argv2list.c \
									  input_control.c \
									  parse_input.c)

# List of object files
OBJ_DIR		= obj/
OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# List of header files
INC_DIR		= includes/
INLCUDES	= $(addprefix includes/, push_swap.h)

# Compilation flags
CC			= cc
RM			= rm -rf
AR			= ar
DIR_DUP		= mkdir -p $(@D)

CFLAGS 		+= -Wall -Wextra -Werror -I includes -I libft/includes
ARFLAGS		= -r -c -s

# Rule name protection
.PHONY:		all libft clean fclean re

all: 		$(NAME)

# Make rules
$(NAME):	$(LIBFT) $(OBJ) $(INLCUDES)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
			make -C $(LIBFT_PATH) all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			make -C $(LIBFT_PATH) clean
			$(RM) $(OBJ)

fclean:		clean
			make -C $(LIBFT_PATH) fclean
			$(RM) $(NAME)

re:			fclean all
