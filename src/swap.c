/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:54:17 by javjimen          #+#    #+#             */
/*   Updated: 2024/07/02 19:18:16 by javjimen         ###   ########.fr       */
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

//void	sa(t_list **stack_a, t_list **stack_o)
void	sa(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	swap(stack_a);
	add_operation(stack_o, SA);
	/* debug */
	ft_printf("-> ");
	ft_printf(SA);
	ft_printf("\n");
	//print_stacks(stack_a, stack_b);
	print_stacks_w_index(stack_a, stack_b);
}

//void	sb(t_list **stack_b, t_list **stack_o)
void	sb(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	swap(stack_b);
	add_operation(stack_o, SB);
	/* debug */
	ft_printf("-> ");
	ft_printf(SB);
	ft_printf("\n");
	//print_stacks(stack_a, stack_b);
	print_stacks_w_index(stack_a, stack_b);
}

void	ss(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	swap(stack_a);
	swap(stack_b);
	add_operation(stack_o, SS);
	/* debug */
	ft_printf("-> ");
	ft_printf(SS);
	ft_printf("\n");
	//print_stacks(stack_a, stack_b);
	print_stacks_w_index(stack_a, stack_b);
}
