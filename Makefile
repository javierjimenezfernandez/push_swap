# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 23:21:14 by javjimen          #+#    #+#              #
#    Updated: 2024/07/02 20:20:49 by javjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME		= push_swap

# Dependancies
LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

# List of source files
SRC_DIR		= src/
SRC			= $(addprefix $(SRC_DIR), main.c \
									  stack_utils.c \
									  split_argv2list.c \
									  input_control.c \
									  swap.c \
									  push.c \
									  rotate.c \
									  reverse_rotate.c \
									  compute_operations.c \
									  small_algorithm.c \
									  middle_algorithm.c \
									  big_algorithm.c \
									  assign_index.c \
									  init.c)

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

SANITIZE	= $(CFLAGS) -fsanitize=address

# Rule name protection
.PHONY:		all libft clean fclean re sanitize

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
			$(RM) $(OBJ_DIR)

fclean:		clean
			make -C $(LIBFT_PATH) fclean
			$(RM) $(NAME)

re:			fclean all

sanitize:	$(LIBFT) $(OBJ) $(INLCUDES)
			$(CC) $(SANITIZE) $(OBJ) -o $(NAME) $(LIBFT)
