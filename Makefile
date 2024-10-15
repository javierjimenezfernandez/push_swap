# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 23:21:14 by javjimen          #+#    #+#              #
#    Updated: 2024/10/15 20:15:19 by javjimen         ###   ########.fr        #
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
									  content_management/get_content.c \
									  content_management/set_content.c \
									  content_management/print_content.c \
									  utils/ps_math.c \
									  utils/stack_utils.c \
									  utils/free_stack.c \
									  utils/assign_index.c \
									  utils/print_stack.c \
									  utils/print_stack_row.c \
									  input/split_argv2list.c \
									  input/input_control.c \
									  operations/swap.c \
									  operations/push.c \
									  operations/rotate.c \
									  operations/reverse_rotate.c \
									  operations/special_rotations.c \
									  operations/add_operation.c \
									  operations/print_operations.c \
									  algorithm/compute_operations.c \
									  algorithm/small_algorithm.c \
									  algorithm/big_algorithm.c \
									  algorithm/big_algorithm_pb.c \
									  algorithm/big_algorithm_pa_back.c)

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
