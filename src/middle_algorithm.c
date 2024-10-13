/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:20:05 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/10 20:08:18 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_to_next_smaller(t_list **stack, t_list *node)
{
	int		candidate;
	int		distance;
	int		count;
	t_list	*i;

	candidate = smallest(stack);
	distance = distance_to_smallest(stack);
	if (*(int *)(node->content) < candidate)
		return (distance);
	count = 0;
	i = *stack;
	while (i)
	{
		if ((*(int *)(i->content) < *(int *)(node->content)) && \
			(*(int *)(i->content) > candidate))
		{
			candidate = *(int *)(i->content);
			distance = count;
		}
		count++;
		i = i->next;
	}
	return (distance);
}

int	distance_to_next_bigger(t_list **stack, t_list *node)
{
	int		candidate;
	int		distance;
	int		count;
	t_list	*i;

	candidate = biggest(stack);
	distance = distance_to_biggest(stack);
	if (*(int *)(node->content) > candidate)
		return (distance);
	count = 0;
	i = *stack;
	while (i)
	{
		if ((*(int *)(i->content) > *(int *)(node->content)) && \
			(*(int *)(i->content) < candidate))
		{
			candidate = *(int *)(i->content);
			distance = count;
		}
		count++;
		i = i->next;
	}
	return (distance);
}

int	compute_r_distance(t_list **stack, t_list *node)
{
	int		ra_count;
	t_list	*i;

	ra_count = 0;
	if (distance_to_smallest(stack))
		ra_count = distance_to_next_bigger(stack, node);
	else
	{
		i = *stack;
		while (i)
		{
			if (*(int *)(i->content) > *(int *)(node->content))
				break ;
			ra_count++;
			i = i->next;
		}
	}
	return (ra_count);
}

void	push_back_numbers(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	int	ra_count;
	int	rra_count;

	while (ft_lstsize(*stack_b))
	{
		ra_count = compute_r_distance(stack_a, *stack_b);
		rra_count = ft_lstsize(*stack_a) - ra_count;
		if (ra_count <= rra_count)
		{
			while (ra_count--)
				ra(stack_a, stack_o);
		}
		else
		{
			while (rra_count--)
				rra(stack_a, stack_o);
		}
		pa(stack_a, stack_b, stack_o);
	}
}

void	middle_algorithm(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size)
{
	int	pb_count;
	int	ra_count;
	int	rra_count;

	pb_count = stack_size - 3;
	while (pb_count--)
		pb(stack_a, stack_b, stack_o);
	small_algorithm(stack_a, stack_o, ft_lstsize(*stack_a));
	push_back_numbers(stack_a, stack_b, stack_o);
	ra_count = distance_to_smallest(stack_a);
	rra_count = stack_size - ra_count;
	if (ra_count <= rra_count)
	{
		while (ra_count--)
			ra(stack_a, stack_o);
	}
	else
	{
		while (rra_count--)
			rra(stack_a, stack_o);
	}
}
