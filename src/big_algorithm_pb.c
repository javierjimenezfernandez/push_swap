/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm_pb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:58:45 by javjimen          #+#    #+#             */
/*   Updated: 2024/08/07 16:55:12 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_chunk_quantity(int stack_size)
{
	int	chunk_num;

	chunk_num = (ft_sqrt(stack_size - 1) / 2) + 1;
	if (chunk_num % 2 != 0)
		chunk_num--;
	return (chunk_num);
}

int	is_in_chunk(t_list	*node, int chunk_min_index, int chunk_max_index)
{
	if (compare_index_value(node, chunk_min_index) >= 0 && \
		compare_index_value(node, chunk_max_index) <= 0)
		return (1);
	else
		return (0);
}

void	assign_cost_by_chnk(t_list **stack_a, int chunk_min_index, \
								int chunk_max_index, int rb_count)
{
	t_list	*i;
	int		ra_count;
	int		rra_count;
	int		cost;

	i = *stack_a;
	ra_count = 0;
	while (i)
	{
		if (is_in_chunk(i, chunk_min_index, chunk_max_index))
		{
			rra_count = ft_lstsize(*stack_a) - ra_count;
			assign_smallest(&cost, ra_count, rra_count);
			cost += rb_count;
			set_cost((t_content *)(i->content), &cost);
		}
		ra_count++;
		i = i->next;
	}
}

t_list	*pb_cheapest(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	int		ra_count;
	int		rra_count;
	t_list	*cheapest;

	ra_count = 0;
	cheapest = get_cheapest(stack_a, &ra_count);
	if (ra_count < ft_lstsize(*stack_a) / 2)
	{
		while (ra_count--)
			ra(stack_a, stack_b, stack_o);
		pb(stack_a, stack_b, stack_o);
	}
	else
	{
		rra_count = ft_lstsize(*stack_a) - ra_count;
		while (rra_count--)
			rra(stack_a, stack_b, stack_o);
		pb(stack_a, stack_b, stack_o);
	}
	return (cheapest);
}

t_ps_error	pb_chunks(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size)
{
	int		chnk_qty;
	int		chnk_sz;
	int		chnk_sz_cnt;
	int		i;

	chnk_qty = compute_chunk_quantity(stack_size);
	chnk_sz = stack_size / chnk_qty;
	if ((stack_size % chnk_qty) != 0)
		chnk_sz += 1;
	i = 0;
	while (2 * i < chnk_qty - 1)
	{
		chnk_sz_cnt = chnk_sz * 2;
		while (chnk_sz_cnt-- && *stack_a)
		{
			assign_cost_by_chnk(stack_a, i * chnk_sz, (i + 1) * chnk_sz - 1, 0);
			assign_cost_by_chnk(stack_a, stack_size - (i + 1) * chnk_sz, \
									stack_size - 1 - (i * chnk_sz), 1);
			if (is_in_chunk(pb_cheapest(stack_a, stack_b, stack_o), \
				stack_size - (i + 1) * chnk_sz, stack_size - 1 - (i * chnk_sz)))
				rb(stack_a, stack_b, stack_o);
		}
		i++;
	}
	return (PS_OK);
}
