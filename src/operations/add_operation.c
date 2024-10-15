/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:12:11 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 12:03:27 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation(t_list **stack_a, t_list **stack_b, \
						t_list **stack_o, char *op_name)
{
	t_list	*new_op;

	new_op = ft_lstnew(ft_strdup(op_name));
	if (!new_op)
	{
		free_stacks(stack_a, stack_b, stack_o, free);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_back(stack_o, new_op);
}
