/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:54:40 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/12 02:09:54 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	int		stack_size;
	t_list	*first;
	t_list	*last;

	stack_size = ft_lstsize(*stack);
	if (stack_size > 1)
	{
		first = *stack;
		*stack = (*stack)->next;
		last = ft_lstlast(*stack);
		last->next = first;
		first->next = NULL;
	}
}

void	ra(t_list **stack_a, t_list **stack_o)
{
	rotate(stack_a);
	add_operation(stack_o, RA);
}

void	rb(t_list **stack_b, t_list **stack_o)
{
	rotate(stack_b);
	add_operation(stack_o, RB);
}

void	rr(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	rotate(stack_a);
	rotate(stack_b);
	add_operation(stack_o, RR);
}
