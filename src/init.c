/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:09:33 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/13 13:06:15 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_error	stacks_init(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	if (!stack_a || !stack_b || !stack_o)
	{
		free_stacks(stack_a, stack_b, stack_o, free);
		return (PS_MALLOC_FAIL);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	*stack_o = NULL;
	return (PS_OK);
}

t_ps_error	init_content(t_content *new_content)
{
	if (!new_content)
	{
		return (PS_MALLOC_FAIL);
	}
	new_content->index = -1;
	new_content->cost = -1;
	new_content->value = 0;
	return (PS_OK);
}
