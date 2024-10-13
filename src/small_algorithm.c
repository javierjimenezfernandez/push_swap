/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:19:47 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/10 20:06:37 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	twonum_logic(t_list **stack_a, t_list **stack_o)
{
	t_list	*first;
	t_list	*second;

	first = *stack_a;
	second = first->next;
	if (*(int *)(first->content) > *(int *)(second->content))
		sa(stack_a, stack_o);
}

void	threenum_logic(t_list **stack_a, t_list **stack_o)
{
	int	d2s;
	int	d2b;

	d2s = distance_to_smallest(stack_a);
	d2b = distance_to_biggest(stack_a);
	if ((d2s == 0 && d2b == 1) || (d2s == 1 && d2b == 2))
	{
		sa(stack_a, stack_o);
		if (d2s == 0 && d2b == 1)
			ra(stack_a, stack_o);
	}
	else if (d2s == 2 && d2b == 1)
		rra(stack_a, stack_o);
	else if (d2b == 0)
	{
		ra(stack_a, stack_o);
		if (d2s == 2)
			sa(stack_a, stack_o);
	}
}

void	small_algorithm(t_list **stack_a, t_list **stack_o, int stack_size)
{
	if (stack_size == 2)
		twonum_logic(stack_a, stack_o);
	if (stack_size == 3)
		threenum_logic(stack_a, stack_o);
}
