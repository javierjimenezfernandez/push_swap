/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_pa_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:52:55 by javjimen          #+#    #+#             */
/*   Updated: 2024/08/07 18:15:02 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* tengo que computar el coste para cada elemento, encontrar el más barato
y pushearlo de vuelta. Tener en cuenta la doble rotación (ra + rb = rr e
ídem para reverse)*/

int	compute_cost_before_push(t_list **stack, t_list *node)
{
	int		r_count;
	t_list	*i;
	t_list	*j;

	i = *stack;
	j = i->next;
	while (j)
	{
		if (compare_values(i, node) < 0 && compare_values(node, j) < 0)
			break ;
		r_count++;
		i = i->next;
		j = j->next;
	}
	if (compare_values(i, node) < 0 && compare_values(node, *stack) < 0)
		r_count = 0;
	return (r_count);
}

void	assign_cost2all(t_list **stack_a, t_list **stack_b)
{
	int		cost;
	int		ra_cost;
	int		rb_cost;
	t_list	*i;

	rb_cost = 0;
	i = *stack_b;
	while (i)
	{
		cost = 0;
		ra_cost = compute_r_before_push(stack_a, i);
		add_smallest(&cost, ra_cost, ft_lstsize(*stack_a) - ra_cost);
		add_smallest(&cost, rb_cost, ft_lstsize(*stack_b) - rb_cost);
		set_cost((t_content *)i->content, &cost);
		rb_cost++;
		i = i->next;
	}
}

t_ps_error	pa_back(t_list **stack_a, t_list **stack_b, \
						t_list **stack_o, int stack_size)
{
	/* pushear un par de elementos a stack_a y a partir de ahí lanzar el algoritmo
	(aquí o en big_algorithm)*/
}
