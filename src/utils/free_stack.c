/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:20:22 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 10:21:29 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack, void (*del)(void *))
{
	ft_lstclear(stack, del);
}

void	free_stacks(t_list **stack_a, t_list **stack_b, t_list **stack_o, \
						void (*del)(void *))
{
	free_stack(stack_a, del);
	free_stack(stack_b, del);
	free_stack(stack_o, free);
}
