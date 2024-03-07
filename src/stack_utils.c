/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:45:23 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/07 17:38:28 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*dummy_node;

	dummy_node = NULL;
	stack_a = &dummy_node;
	stack_b = &dummy_node;
}

void	free_stack(t_list **stack)
{
	ft_lstclear(stack, free);
	free(stack);
}

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
