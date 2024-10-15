/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:38:07 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 10:42:33 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **stack)
{
	t_list	*i;

	i = *stack;
	while (i)
	{
		ft_printf("%d\n", *(int *)(i->content));
		i = i->next;
	}
}

void	print_stack_w_content(t_list **stack)
{
	t_list	*i;

	i = *stack;
	ft_printf("\tstack\n");
	ft_printf("index\tvalue\tcost\n");
	while (i)
	{
		print_index(i);
		ft_printf("\t");
		print_value(i);
		ft_printf("\t");
		print_cost(i);
		ft_printf("\n");
		i = i->next;
	}
}

void	print_stacks_w_content(t_list **stack_a, t_list **stack_b)
{
	t_list	*i;
	t_list	*j;

	i = *stack_a;
	j = *stack_b;
	ft_printf("\tstack_a\t\t|\t\tstack_b\t\n");
	ft_printf("index\tvalue\tcost\t|\tindex\tvalue\tcost\n");
	while (i || j)
	{
		print_row(&i, &j);
	}
}
