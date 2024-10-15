/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:54:29 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/14 17:13:23 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list	**dst_stack, t_list **src_stack)
{
	int		src_stack_size;
	t_list	*src_first;

	src_stack_size = ft_lstsize(*src_stack);
	if (src_stack_size > 0)
	{
		src_first = *src_stack;
		*src_stack = (*src_stack)->next;
		src_first->next = *dst_stack;
		*dst_stack = src_first;
	}
}

void	pa(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	push(stack_a, stack_b);
	add_operation(stack_a, stack_b, stack_o, PA);
}

void	pb(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	push(stack_b, stack_a);
	add_operation(stack_a, stack_b, stack_o, PB);
}
