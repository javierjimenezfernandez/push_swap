/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:49 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/14 17:33:25 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

/* push_swap magic numbers */
# define PS_OK			0
# define PS_ERROR		1
# define PS_MALLOC_FAIL	2
# define MAX_INT		"2147483647"
# define MIN_INT		"-2147483648"

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

/* typedef */
typedef int	t_ps_error;
typedef struct s_content
{
	int	index;
	int	cost;
	int	value;
}				t_content;
typedef struct s_rot_costs
{
	int	ra_cost;
	int	rra_cost;
	int	rb_cost;
	int	rrb_cost;
}				t_rot_costs;

/* main */
int			main(int argc, char **argv);

/* stack utils */
void		free_stack(t_list **stack, void (*del)(void *));
void		free_stacks(t_list **stack_a, t_list **stack_b, t_list **stack_o, \
							void (*del)(void *));
void		print_stack(t_list **stack);
void		print_stacks(t_list **stack_a, t_list **stack_b);
int			get_index(t_list *node);
int			get_cost(t_list *node);
int			get_value(t_list *node);
void		set_index(t_list *node, int index);
void		set_cost(t_list *node, int cost);
void		set_value(t_list *node, int value);
void		print_index(t_list *node);
void		print_value(t_list *node);
void		print_cost(t_list *node);
void		print_stack_w_content(t_list **stack);
void		print_stacks_w_content(t_list **stack_a, t_list **stack_b);
t_list		*get_smallest(t_list **stack);
t_list		*get_biggest(t_list **stack);
int			r_distance_to_node(t_list **stack, t_list *node);
int			compare_values(t_list *node_a, t_list *node_b);
int			compare_index(t_list *node_a, t_list *node_b);
int			compare_index_w_int(t_list *node_a, int index);
int			compare_cost(t_list *node_a, t_list *node_b);
void		add_operation(t_list **stack_o, char *op_name);
void		print_operations(t_list **stack);
int			ft_max2(int a, int b);
int			ft_max3(int a, int b, int c);
int			ft_min2(int a, int b);
int			ft_min3(int a, int b, int c);
int			ft_sqrt(int nb);

/* split argv2list */
t_ps_error	s_array_free(char **s_array);
t_ps_error	split_argv2list(char **argv, t_list **stack_a);

/* input control */
t_ps_error	is_bigger_than_int(char *str, int len);
t_ps_error	is_format_incorrect(char *str);
t_ps_error	parse_input(t_list **lst);
t_ps_error	is_duplicated(int num1, int num2);
t_ps_error	input_control(t_list **stack_a);

/* swap */
void		swap(t_list **stack);
void		sa(t_list **stack_a, t_list **stack_o);
void		sb(t_list **stack_b, t_list **stack_o);
void		ss(t_list **stack_a, t_list **stack_b, t_list **stack_o);

/* push */
void		push(t_list	**dst_stack, t_list **src_stack);
void		pa(t_list **stack_a, t_list **stack_b, t_list **stack_o);
void		pb(t_list **stack_a, t_list **stack_b, t_list **stack_o);

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

/* compute operations */
t_ps_error	compute_operations(t_list **stack_a, t_list **stack_b, \
								t_list **stack_o, int stack_size);

/* small algorithm */
void		twonum_logic(t_list **stack_a, t_list **stack_o);
void		threenum_logic(t_list **stack_a, t_list **stack_o);
void		small_algorithm(t_list **stack_a, t_list **stack_o, int stack_size);

/* big algorithm */
void		put_smaller_first(t_list **stack_a, t_list **stack_o, \
								int stack_size);
t_list		*get_cheapest(t_list **stack, int *r_count);
t_ps_error	big_algorithm(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size);

/* big algorithm pb */
void		compute_chnk_qty_nd_sz(int *chnk_qty, int *chnk_sz, int stack_size);
int			is_in_chunk(t_list	*node, int chunk_min_index, \
							int chunk_max_index);
void		assign_cost_by_chnk(t_list **stack_a, int chunk_min_index, \
									int chunk_max_index, int rb_count);
t_list		*pb_cheapest(t_list **stack_a, t_list **stack_b, t_list **stack_o);
t_ps_error	pb_chunks(t_list **stack_a, t_list **stack_b, \
						t_list **stack_o, int stack_size);

/* big algorithm pa back */
void		perform_cheapest_rot(t_rot_costs costs, t_list **stack_a, \
									t_list **stack_b, t_list **stack_o);
int			compute_cost(int ra_count, int stack_size_a, int rb_count, \
							int stack_size_b);
int			compute_r_before_push(t_list **stack, t_list *node);
void		assign_cost2all(t_list **stack_a, t_list **stack_b, \
								int stack_size_a, int stack_size_b);
t_ps_error	pa_back(t_list **stack_a, t_list **stack_b, t_list **stack_o);

/* assign index */
t_list		*node_w_new_content(t_list *i);
t_ps_error	add_content(t_list **stack);
t_list		*find_next(t_list **stack, t_list *candidate, \
						t_list *prev_candidate);
t_ps_error	assign_index(t_list **stack);

/* special rotations */
void		ra_rb_rr(t_rot_costs costs, t_list **stack_a, \
						t_list **stack_b, t_list **stack_o);
void		rra_rrb_rrr(t_rot_costs costs, t_list **stack_a, \
						t_list **stack_b, t_list **stack_o);
void		ra_rrb_or_ra_rb_rr_or_ra_rb_rr(t_rot_costs costs, t_list **stack_a, \
											t_list **stack_b, t_list **stack_o);
void		rra_rb_or_ra_rb_rr_or_ra_rb_rr(t_rot_costs costs, t_list **stack_a, \
											t_list **stack_b, t_list **stack_o);

/* init */
t_ps_error	init_content(t_content *new_content);

#endif
