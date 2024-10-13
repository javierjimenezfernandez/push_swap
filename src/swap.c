/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:54:17 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/10 19:27:24 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int		stack_size;
	t_list	*first;
	t_list	*third;

	stack_size = ft_lstsize(*stack);
	if (stack_size > 1)
	{
		first = *stack;
		*stack = (*stack)->next;
		third = (*stack)->next;
		first->next = third;
		(*stack)->next = first;
	}
}

void	sa(t_list **stack_a, t_list **stack_o)
{
	swap(stack_a);
	add_operation(stack_o, SA);
}

void	sb(t_list **stack_b, t_list **stack_o)
{
	swap(stack_b);
	add_operation(stack_o, SB);
}

void	ss(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	swap(stack_a);
	swap(stack_b);
	add_operation(stack_o, SS);
}
