/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:49 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/14 01:23:25 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

/* push_swap magic numbers */
# define PS_OK		0
# define PS_ERROR	1
# define MAX_INT	"2147483647"
# define MIN_INT	"-2147483648"

/* push swap opeation names */
# define SA		"sa"
# define SB		"sb"
# define SS		"ss"
# define PA		"pa"
# define PB		"pb"
# define RA		"ra"
# define RB		"rb"
# define RR		"rr"
# define RRA	"rra"
# define RRB	"rrb"
# define RRR	"rrr"

/* stack size limits for chunk division */
/* series based on sqrt(x)/(log of x base sqrt(x))*/
# define STACK_SIZE_1	16
# define STACK_SIZE_2	36
# define STACK_SIZE_3	64
# define STACK_SIZE_4	100
# define STACK_SIZE_5	144
# define STACK_SIZE_6	196
# define STACK_SIZE_7	256
# define STACK_SIZE_8	324
# define STACK_SIZE_9	400
# define STACK_SIZE_10	484
# define STACK_SIZE_11	576
# define STACK_SIZE_12	676
# define STACK_SIZE_13	784
# define STACK_SIZE_14	900
# define STACK_SIZE_15	1024

/* typedef */
typedef int	t_ps_error;
typedef struct s_psnode
{
	int				index;
	void			*value;
	struct s_psnode	*prev;
	struct s_psnode	*next;
}				t_psnode;

/* main */
int			main(int argc, char **argv);

/* stack utils */
void		free_stack(t_list **stack);
void		free_stacks(t_list **stack_a, t_list **stack_b, t_list **stack_o);
t_list		*return_second2last(t_list **stack);
void		print_stack(t_list **stack);
void		print_stacks(t_list **stack_a, t_list **stack_b);
void		add_operation(t_list **stack_o, char *op_name);
void		print_operations(t_list **stack);
int			smallest(t_list **stack);
int			distance_to_smallest(t_list **stack);
int			distance_and_smallest(t_list **stack, int *smallest);
int			biggest(t_list **stack);
int			distance_to_biggest(t_list **stack);
int			distance_and_biggest(t_list **stack, int *biggest);

/* split argv2list */
void		s_array_free(char **s_array, int count);
t_ps_error	split_argv2list(int argc, char **argv, t_list **stack_a);

/* input control */
t_ps_error	is_bigger_than_int(char *str, int len);
t_ps_error	is_duplicated(char *str1, char *str2);
t_ps_error	is_format_incorrect(char *str);
t_ps_error	input_control(t_list **stack_a);

/* parse input */
t_ps_error	parse_input(t_list **lst);

/* swap */
void		swap(t_list **stack);
//void		sa(t_list **stack_a, t_list **stack_o);
//void		sb(t_list **stack_b, t_list **stack_o);
void		sa(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		sb(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		ss(t_list **stack_a, t_list **stack_b, t_list **stack_o);

/* push */
void		push(t_list	**dst_stack, t_list **src_stack);
void		pa(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		pb(t_list **stack_b, t_list **stack_a, t_list **stack_o);

/* rotate */
void		rotate(t_list **stack);
//void		ra(t_list **stack_a, t_list **stack_o);
//void		rb(t_list **stack_b, t_list **stack_o);
void		ra(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		rb(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		rr(t_list **stack_a, t_list **stack_b, t_list **stack_o);

/* reverse rotate */
void		reverse_rotate(t_list **stack);
//void		rra(t_list **stack_a, t_list **stack_o);
//void		rrb(t_list **stack_b, t_list **stack_o);
void		rra(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		rrb(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		rrr(t_list **stack_a, t_list **stack_b, t_list **stack_o);

/* compute operations */
void		select_algorithm(t_list **stack_a, t_list **stack_b, \
								t_list **stack_o, int stack_size);
void		compute_operations(t_list **stack_a, t_list **stack_b, \
								t_list **stack_o, int stack_size);

/* small algorithm */
//void		twonum_logic(t_list **stack_a, t_list **stack_o);
//void		threenum_logic(t_list **stack_a, t_list **stack_o);
//void		small_algorithm(t_list **stack_a, t_list **stack_o, int stack_size);
void		twonum_logic(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		threenum_logic(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		small_algorithm(t_list **stack_a, t_list **stack_b, t_list **stack_o, int stack_size);

/* middle algorithm */
int			distance_to_next_smaller(t_list **stack, t_list *node);
int			distance_to_next_bigger(t_list **stack, t_list *node);
int			compute_r_distance(t_list **stack, t_list *node);
void		push_back_numbers(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o);
void		middle_algorithm(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size);

/* big algorithm */
void		big_algorithm(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size);

#endif
