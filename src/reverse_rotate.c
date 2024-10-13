/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:55:05 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/13 14:39:09 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	int		stack_size;
	t_list	*second_to_last;
	t_list	*last;

	stack_size = ft_lstsize(*stack);
	if (stack_size > 1)
	{
		second_to_last = *stack;
		while ((second_to_last->next)->next)
			second_to_last = second_to_last->next;
		last = ft_lstlast(*stack);
		last->next = *stack;
		*stack = last;
		second_to_last->next = NULL;
	}
}

void	rra(t_list **stack_a, t_list **stack_o)
{
	reverse_rotate(stack_a);
	add_operation(stack_o, RRA);
}

void	rrb(t_list **stack_b, t_list **stack_o)
{
	reverse_rotate(stack_b);
	add_operation(stack_o, RRB);
}

void	rrr(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	add_operation(stack_o, RRR);
}
