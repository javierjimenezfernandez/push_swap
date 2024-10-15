/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:45:23 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 11:12:32 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_smallest(t_list **stack)
{
	t_list	*i;
	t_list	*candidate;

	i = *stack;
	candidate = *stack;
	i = i->next;
	while (i)
	{
		if (get_value(i) < get_value(candidate))
			candidate = i;
		i = i->next;
	}
	return (candidate);
}

t_list	*get_biggest(t_list **stack)
{
	t_list	*i;
	t_list	*candidate;

	i = *stack;
	candidate = *stack;
	i = i->next;
	while (i)
	{
		if (get_value(i) > get_value(candidate))
			candidate = i;
		i = i->next;
	}
	return (candidate);
}

int	r_distance_to_node(t_list **stack, t_list *node)
{
	int		r_count;
	t_list	*i;

	r_count = 0;
	i = *stack;
	while (i)
	{
		if (get_value(i) == get_value(node))
			break ;
		r_count++;
		i = i->next;
	}
	return (r_count);
}
