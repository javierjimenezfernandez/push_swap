/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:49 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/12 02:07:59 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/* push_swap magic numbers */
#define PS_OK		0
#define PS_ERROR	1
#define MAX_INT		"2147483647"
#define MIN_INT		"-2147483648"

/* push swap opeation names */
#define SA	"sa"
#define SB	"sb"
#define SS	"ss"
#define PA	"pa"
#define PB	"pb"
#define RA	"ra"
#define RB	"rb"
#define RR	"rr"
#define RRA	"rra"
#define RRB	"rrb"
#define RRR	"rrr"

/* typedef */
typedef int	t_ps_error;

/* push swap */
int			main(int argc, char **argv);

/* stack utils */
void		init_stack(t_list **stack_a, t_list **stack_b);
void		free_stack(t_list **stack);
void		free_stacks(t_list **stack_a, t_list **stack_b, t_list **stack_o);
t_list		*return_second2last(t_list **stack);
void		print_stack(t_list **stack);
void		print_stacks(t_list **stack_a, t_list **stack_b);
void		add_operation(t_list **stack_o, char *op_name);
void		print_operations(t_list **stack);

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
void		sa(t_list **stack_a, t_list **stack_o);
void		sb(t_list **stack_b, t_list **stack_o);
void		ss(t_list **stack_a, t_list **stack_b, t_list **stack_o);

/* push */
void		push(t_list	**dst_stack, t_list **src_stack);
void		pa(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		pb(t_list **stack_b, t_list **stack_a, t_list **stack_o);

/* rotate */
void		rotate(t_list **stack);
void		ra(t_list **stack_a, t_list **stack_o);
void		rb(t_list **stack_b, t_list **stack_o);
void		rr(t_list **stack_a, t_list **stack_b, t_list **stack_o);

/* reverse rotate */
void		reverse_rotate(t_list **stack);
void		rra(t_list **stack_a, t_list **stack_o);
void		rrb(t_list **stack_b, t_list **stack_o);
void		rrr(t_list **stack_a, t_list **stack_b, t_list **stack_o);
