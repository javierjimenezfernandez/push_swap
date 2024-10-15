/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:20:19 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/14 17:28:57 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_smaller_first(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size)
{
	int		ra_count;
	int		rra_count;
	t_list	*smallest;

	smallest = get_smallest(stack_a);
	ra_count = r_distance_to_node(stack_a, smallest);
	rra_count = stack_size - ra_count;
	if (ra_count <= rra_count)
	{
		while (ra_count--)
			ra(stack_a, stack_b, stack_o);
	}
	else
	{
		while (rra_count--)
			rra(stack_a, stack_b, stack_o);
	}
}

t_list	*get_cheapest(t_list **stack, int *r_count)
{
	int		count;
	int		first_candidate;
	t_list	*i;
	t_list	*cheapest;

	cheapest = *stack;
	first_candidate = 1;
	count = 0;
	i = *stack;
	while (i)
	{
		if (get_cost(i) >= 0)
		{
			if (first_candidate || compare_cost(i, cheapest) < 0)
			{
				cheapest = i;
				*r_count = count;
				first_candidate = 0;
			}
		}
		count++;
		i = i->next;
	}
	return (cheapest);
}

t_ps_error	big_algorithm(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size)
{
	pb_chunks(stack_a, stack_b, stack_o, stack_size);
	small_algorithm(stack_a, stack_b, stack_o, ft_lstsize(*stack_a));
	pa_back(stack_a, stack_b, stack_o);
	put_smaller_first(stack_a, stack_b, stack_o, stack_size);
	return (PS_OK);
}
