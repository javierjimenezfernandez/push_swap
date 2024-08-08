/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:54:40 by javjimen          #+#    #+#             */
/*   Updated: 2024/07/04 20:29:55 by javjimen         ###   ########.fr       */
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

//void	ra(t_list **stack_a, t_list **stack_o)
void	ra(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	rotate(stack_a);
	add_operation(stack_o, RA);
	/* debug */
	ft_printf("-> ");
	ft_printf(RA);
	ft_printf("\n");
	if ((ft_lstsize(*stack_a) + ft_lstsize(*stack_b)) <= 6)
		print_stacks(stack_a, stack_b);
	else
		print_stacks_w_index(stack_a, stack_b);
}

//void	rb(t_list **stack_b, t_list **stack_o)
void	rb(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	rotate(stack_b);
	add_operation(stack_o, RB);
	/* debug */
	ft_printf("-> ");
	ft_printf(RB);
	ft_printf("\n");
	if ((ft_lstsize(*stack_a) + ft_lstsize(*stack_b)) <= 6)
		print_stacks(stack_a, stack_b);
	else
		print_stacks_w_index(stack_a, stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	rotate(stack_a);
	rotate(stack_b);
	add_operation(stack_o, RR);
	/* debug */
	ft_printf("-> ");
	ft_printf(RR);
	ft_printf("\n");
	if ((ft_lstsize(*stack_a) + ft_lstsize(*stack_b)) <= 6)
		print_stacks(stack_a, stack_b);
	else
		print_stacks_w_index(stack_a, stack_b);
}
