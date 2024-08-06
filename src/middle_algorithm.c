/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:20:05 by javjimen          #+#    #+#             */
/*   Updated: 2024/07/04 20:22:27 by javjimen         ###   ########.fr       */
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
	/* debug */
	ft_printf("in distance_to_next_smaller: distance_to_biggest = %d\n", distance_to_smallest(stack));
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
	/* debug */
	ft_printf("in distance_to_next_smaller: actual computed distance = %d\n", distance);
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
	/* debug */
	ft_printf("in distance_to_next_bigger: distance_to_biggest = %d\n", distance_to_biggest(stack));
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
	/* debug */
	ft_printf("in distance_to_next_bigger: actual computed distance = %d\n", distance);
	return (distance);
}

int	compute_r_distance(t_list **stack, t_list *node)
{
	int		ra_count;
	t_list	*i;

	ra_count = 0;
	/* debug */
	ft_printf("in compute_r_distance: node = %p\n", node);
	ft_printf("in compute_r_distance: node->content = %d\n", *(int *)(node->content));
	ft_printf("in compute_r_distance: distance_to_smallest = %d\n", distance_to_smallest(stack));
	if (distance_to_smallest(stack))
		ra_count = distance_to_next_bigger(stack, node);
	else
	{
		i = *stack;
		while (i)
		{
			/* debug */
			ft_printf("in compute_r_distance: hello there2\n");
			if (*(int *)(i->content) > *(int *)(node->content))
			{
				/* debug */
				ft_printf("in compute_r_distance: hello there3\n");
				break ;
			}
			ra_count++;
			i = i->next;
		}
	}
	/* debug */
	ft_printf("in compute_r_distance: distance_to_next_bigger (function) = %d\n", distance_to_next_bigger(stack, node));
	ft_printf("in compute_r_distance: computed r distance (ra_count) = %d\n", ra_count);
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
		/* debug */
		ft_printf("in push_back_numbers: ra_count = %d, rra_count = %d\n", ra_count, rra_count);
		if (ra_count <= rra_count)
		{
			while (ra_count--)
				ra(stack_a, stack_b, stack_o);
				//ra(stack_a, stack_o);
		}
		else
		{
			while (rra_count--)
				rra(stack_a, stack_b, stack_o);
				//rra(stack_a, stack_o);
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
	//small_algorithm(stack_a, stack_o, ft_lstsize(*stack_a));
	small_algorithm(stack_a, stack_b, stack_o, ft_lstsize(*stack_a));
	push_back_numbers(stack_a, stack_b, stack_o);
	ra_count = distance_to_smallest(stack_a);
	rra_count = stack_size - ra_count;
	if (ra_count <= rra_count)
	{
		while (ra_count--)
			ra(stack_a, stack_b, stack_o);
			//ra(stack_a, stack_o);
	}
	else
	{
		while (rra_count--)
			rra(stack_a, stack_b, stack_o);
			//rra(stack_a, stack_o);
	}
}
