/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:55:05 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/14 15:05:07 by javjimen         ###   ########.fr       */
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
		second_to_last = return_second2last(stack);
		last = ft_lstlast(*stack);
		last->next = *stack;
		*stack = last;
		second_to_last->next = NULL;
	}
}

//void	rra(t_list **stack_a, t_list **stack_o)
void	rra(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	reverse_rotate(stack_a);
	add_operation(stack_o, RRA);
	/* debug */
	ft_printf("-> ");
	ft_printf(RRA);
	ft_printf("\n");
	print_stacks(stack_a, stack_b);
}

//void	rrb(t_list **stack_b, t_list **stack_o)
void	rrb(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	reverse_rotate(stack_b);
	add_operation(stack_o, RRB);
	/* debug */
	ft_printf("-> ");
	ft_printf(RRB);
	ft_printf("\n");
	print_stacks(stack_a, stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	add_operation(stack_o, RRR);
	/* debug */
	ft_printf("-> ");
	ft_printf(RRR);
	ft_printf("\n");
	print_stacks(stack_a, stack_b);
}
