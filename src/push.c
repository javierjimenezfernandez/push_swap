/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:54:29 by javjimen          #+#    #+#             */
/*   Updated: 2024/07/02 19:17:04 by javjimen         ###   ########.fr       */
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
	add_operation(stack_o, PA);
	/* debug */
	ft_printf("-> ");
	ft_printf(PA);
	ft_printf("\n");
	//print_stacks(stack_a, stack_b);
	print_stacks_w_index(stack_a, stack_b);
}

void	pb(t_list **stack_b, t_list **stack_a, t_list **stack_o)
{
	push(stack_b, stack_a);
	add_operation(stack_o, PB);
	/* debug */
	ft_printf("-> ");
	ft_printf(PB);
	ft_printf("\n");
	//print_stacks(stack_a, stack_b);
	print_stacks_w_index(stack_a, stack_b);
}
