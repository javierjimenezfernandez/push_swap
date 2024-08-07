/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:20:19 by javjimen          #+#    #+#             */
/*   Updated: 2024/08/07 15:02:49 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_cheapest(t_list **stack, int *ra_count)
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
		if (get_cost((t_content *)(i->content)) >= 0)
		{
			if (first_candidate || compare_cost(i, cheapest) < 0)
			{
				cheapest = i;
				*ra_count = count;
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
	if (assign_index(stack_a) == PS_MALLOC_FAIL)
	{
		free_stacks(stack_a, stack_b, stack_o, free);
		return (PS_MALLOC_FAIL);
	}
	pb_chunks(stack_a, stack_b, stack_o, stack_size);
	return (PS_OK);
}
