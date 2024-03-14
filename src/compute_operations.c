/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:28 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/13 23:25:20 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algorithm(t_list **stack_a, t_list **stack_b, \
						t_list **stack_o, int stack_size)
{
	if (stack_size <= 3)
		small_algorithm(stack_a, stack_b, stack_o, stack_size);
		//small_algorithm(stack_a, stack_o, stack_size);
	else if (stack_size <= 6)
		middle_algorithm(stack_a, stack_b, stack_o, stack_size);
	else
		big_algorithm(stack_a, stack_b, stack_o, stack_size);
}

void	compute_operations(t_list **stack_a, t_list **stack_b, \
						t_list **stack_o, int stack_size)
{
	if (stack_size == 1)
		return ;
	else
		select_algorithm(stack_a, stack_b, stack_o, stack_size);
}
