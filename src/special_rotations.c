/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:47:02 by javjimen          #+#    #+#             */
/*   Updated: 2024/08/08 21:24:05 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_rr(t_rot_costs costs, t_list **stack_a, \
					t_list **stack_b, t_list **stack_o)
{
	if (costs.ra_cost <= costs.rb_cost)
	{
		while ((costs.ra_cost)--)
		{
			rr(stack_a, stack_b, stack_o);
			(costs.rb_cost)--;
		}
		while ((costs.rb_cost)--)
			rb(stack_a, stack_b, stack_o);
	}
	else
	{
		while ((costs.rb_cost)--)
		{
			rr(stack_a, stack_b, stack_o);
			(costs.ra_cost)--;
		}
		while ((costs.ra_cost)--)
			ra(stack_a, stack_b, stack_o);
	}
}

void	rra_rrb_rrr(t_rot_costs costs, t_list **stack_a, \
					t_list **stack_b, t_list **stack_o)
{
	if (costs.rra_cost <= costs.rrb_cost)
	{
		while ((costs.rra_cost)--)
		{
			rrr(stack_a, stack_b, stack_o);
			(costs.rrb_cost)--;
		}
		while ((costs.rrb_cost)--)
			rrb(stack_a, stack_b, stack_o);
	}
	else
	{
		while ((costs.rrb_cost)--)
		{
			rrr(stack_a, stack_b, stack_o);
			(costs.rra_cost)--;
		}
		while ((costs.rra_cost)--)
			rra(stack_a, stack_b, stack_o);
	}
}

void	ra_rrb_or_ra_rb_rr_or_ra_rb_rr(t_rot_costs costs, t_list **stack_a, \
										t_list **stack_b, t_list **stack_o)
{
	if (costs.ra_cost + costs.rrb_cost <= \
		ft_min2(ft_max2(costs.ra_cost, costs.rb_cost), \
				ft_max2(costs.rra_cost, costs.rrb_cost)))
	{
		while ((costs.ra_cost)--)
			ra(stack_a, stack_b, stack_o);
		while ((costs.rrb_cost)--)
			rrb(stack_a, stack_b, stack_o);
	}
	else if (ft_max2(costs.ra_cost, costs.rb_cost) <= \
			ft_min2(costs.ra_cost + costs.rrb_cost, \
					ft_max2(costs.rra_cost, costs.rrb_cost)))
		ra_rb_rr(costs, stack_a, stack_b, stack_o);
	else
		ra_rb_rr(costs, stack_a, stack_b, stack_o);
}

void	rra_rb_or_ra_rb_rr_or_ra_rb_rr(t_rot_costs costs, t_list **stack_a, \
										t_list **stack_b, t_list **stack_o)
{
	if (costs.rra_cost + costs.rb_cost <= \
		ft_min2(ft_max2(costs.ra_cost, costs.rb_cost), \
						ft_max2(costs.rra_cost, costs.rrb_cost)))
	{
		while ((costs.rra_cost)--)
			rra(stack_a, stack_b, stack_o);
		while ((costs.rb_cost)--)
			rb(stack_a, stack_b, stack_o);
	}
	else if (ft_max2(costs.ra_cost, costs.rb_cost) <= \
			ft_min2(costs.rra_cost + costs.rb_cost, \
					ft_max2(costs.rra_cost, costs.rrb_cost)))
		ra_rb_rr(costs, stack_a, stack_b, stack_o);
	else
		rra_rrb_rrr(costs, stack_a, stack_b, stack_o);
}
