/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:28 by javjimen          #+#    #+#             */
/*   Updated: 2024/06/28 19:45:10 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_error	select_algorithm(t_list **stack_a, t_list **stack_b, \
						t_list **stack_o, int stack_size)
{
	if (stack_size <= 3)
		small_algorithm(stack_a, stack_b, stack_o, stack_size);
		//small_algorithm(stack_a, stack_o, stack_size);
	else if (stack_size <= 6)
		middle_algorithm(stack_a, stack_b, stack_o, stack_size);
	else
		return(big_algorithm(stack_a, stack_b, stack_o, stack_size));
	return (PS_OK);
}

t_ps_error	compute_operations(t_list **stack_a, t_list **stack_b, \
						t_list **stack_o, int stack_size)
{
	if (stack_size == 1)
		return (PS_OK);
	else
		return(select_algorithm(stack_a, stack_b, stack_o, stack_size));
}
