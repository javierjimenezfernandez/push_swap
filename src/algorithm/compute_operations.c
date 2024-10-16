/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:28 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 18:56:59 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_already_sorted(t_list **stack)
{
	int		sorted_flag;
	t_list	*i;

	sorted_flag = 1;
	i = *stack;
	while (i->next)
	{
		if (get_value(i) > get_value(i->next))
			sorted_flag = 0;
		i = i->next;
	}
	return (sorted_flag);
}

t_ps_error	compute_operations(t_list **stack_a, t_list **stack_b, \
						t_list **stack_o, int stack_size)
{
	if (stack_size == 1)
		return (PS_OK);
	else
	{
		if (assign_index(stack_a) == PS_MALLOC_FAIL)
		{
			free_stack(stack_a, free);
			ft_putstr_fd("Error\n", 2);
			return (PS_MALLOC_FAIL);
		}
		if (is_already_sorted(stack_a))
			return (PS_OK);
		if (stack_size <= 3)
			small_algorithm(stack_a, stack_b, stack_o, stack_size);
		else
			big_algorithm(stack_a, stack_b, stack_o, stack_size);
		return (PS_OK);
	}
}
