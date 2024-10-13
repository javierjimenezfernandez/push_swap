/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_pa_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:52:55 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/10 21:37:26 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* tengo que computar el coste para cada elemento, encontrar el más barato
y pushearlo de vuelta. Tener en cuenta la doble rotación (ra + rb = rr e
ídem para reverse)*/
void	perform_cheapest_rot(t_rot_costs costs, t_list **stack_a, \
								t_list **stack_b, t_list **stack_o)
{
	if (costs.ra_cost <= costs.rra_cost)
	{
		if (costs.rb_cost <= costs.rrb_cost)
			ra_rb_rr(costs, stack_a, stack_b, stack_o);
		else
			ra_rrb_or_ra_rb_rr_or_ra_rb_rr(costs, stack_a, stack_b, stack_o);
	}
	else
	{
		if (costs.rb_cost <= costs.rrb_cost)
			rra_rb_or_ra_rb_rr_or_ra_rb_rr(costs, stack_a, stack_b, stack_o);
		else
			rra_rrb_rrr(costs, stack_a, stack_b, stack_o);
	}
}

int	compute_cost(int ra_count, int stack_size_a, int rb_count, int stack_size_b)
{
	int	cost;
	int	rra_count;
	int	rrb_count;

	rra_count = stack_size_a - ra_count;
	rrb_count = stack_size_b - rb_count;
	if (ra_count <= stack_size_a / 2)
	{
		if (rb_count <= stack_size_b / 2)
			cost = ft_max2(ra_count, rb_count);
		else
			cost = ft_min3(ra_count + rrb_count, ft_max2(ra_count, rb_count), \
							ft_max2(rra_count, rrb_count));
	}
	else
	{
		if (rb_count <= stack_size_b / 2)
			cost = ft_min3(rra_count + rb_count, ft_max2(ra_count, rb_count), \
							ft_max2(rra_count, rrb_count));
		else
			cost = ft_max2(rra_count, rrb_count);
	}
	return (cost);
}

int	compute_r_before_push(t_list **stack, t_list *node)
{
	int		r_count;
	t_list	*smallest;
	t_list	*biggest;
	t_list	*i;
	t_list	*j;

	smallest = get_smallest(stack);
	if (compare_values(node, smallest) < 0)
		return (r_distance_to_node(stack, smallest));
	biggest = get_biggest(stack);
	if (compare_values(biggest, node) < 0)
		return (r_distance_to_node(stack, biggest) + 1);
	r_count = 1;
	i = *stack;
	j = i->next;
	while (j)
	{
		if (compare_values(i, node) < 0 && compare_values(node, j) < 0)
			return (r_count);
		r_count++;
		i = i->next;
		j = j->next;
	}
	return (r_count);
}

void	assign_cost2all(t_list **stack_a, t_list **stack_b, \
						int stack_size_a, int stack_size_b)
{
	int		cost;
	int		ra_count;
	int		rb_count;
	t_list	*i;

	rb_count = 0;
	i = *stack_b;
	while (i)
	{
		cost = 0;
		ra_count = compute_r_before_push(stack_a, i);
		cost = compute_cost(ra_count, stack_size_a, rb_count, stack_size_b);
		set_cost((t_content *)i->content, &cost);
		rb_count++;
		i = i->next;
	}
}

t_ps_error	pa_back(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	t_rot_costs	costs;
	int			stack_size_a;
	int			stack_size_b;
	t_list		*cheapest;

	pa(stack_a, stack_b, stack_o);
	pa(stack_a, stack_b, stack_o);
	if (compare_values((*stack_a)->next, *stack_a) < 0)
		ra(stack_a, stack_o);
	while (*stack_b)
	{
		stack_size_a = ft_lstsize(*stack_a);
		stack_size_b = ft_lstsize(*stack_b);
		assign_cost2all(stack_a, stack_b, stack_size_a, stack_size_b);
		cheapest = get_cheapest(stack_b, &(costs.rb_cost));
		costs.rrb_cost = stack_size_b - costs.rb_cost;
		costs.ra_cost = compute_r_before_push(stack_a, cheapest);
		costs.rra_cost = stack_size_a - costs.ra_cost;
		perform_cheapest_rot(costs, stack_a, stack_b, stack_o);
		pa(stack_a, stack_b, stack_o);
	}
	return (PS_OK);
}
