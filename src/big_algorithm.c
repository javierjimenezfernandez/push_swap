/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:20:19 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/14 01:33:48 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_and_hold_first(t_list **stack, t_list ***hold_first, int chunk_min, int chunk_max)
{
	int		distance;
	t_list	*i;

	distance = 0;
	i = *stack;
	ft_printf("chunk_min = %d\nchunk_max = %d\n", chunk_min, chunk_max);
	while (i)
	{
		if ((*(int *)i->content >= chunk_min) && (*(int *)i->content <= chunk_max))
		{
			(*hold_first) = &i;
			ft_printf("hello\n");
			ft_printf("hold_first->content = %d\n", *(int *)((*(*hold_first))->content));
			break ;
		}
		distance++;
		i = i->next;
	}
	return (distance);
}

int	distance_and_hold_second(t_list **stack, t_list ***hold_second, int chunk_min, int chunk_max)
{
	int		count;
	int		distance;
	t_list	*i;

	count = 0;
	distance = count;
	i = *stack;
	while (i)
	{
		if ((*(int *)i->content >= chunk_min) && (*(int *)i->content <= chunk_max))
		{
			(*hold_second) = &i;
			distance = count;
		}
		count++;
		i = i->next;
	}
	return (distance);
}

int	compute_ra_and_hold(t_list **stack_a, int chunk_min, int chunk_max, t_list **hold)
{
	int		ra_hold_first;
	int		ra_hold_second;
	t_list	**hold_first;
	t_list	**hold_second;

	ra_hold_first = distance_and_hold_first(stack_a, &hold_first, chunk_min, chunk_max);
	ra_hold_second = distance_and_hold_second(stack_a, &hold_second, chunk_min, chunk_max);
	ft_printf("ra_hold_first = %d\n", ra_hold_first);
	ft_printf("ra_hold_second = %d\n", ra_hold_second);
	ft_printf("hold_first->content = %d\n", *(int *)((*hold_first)->content));
	ft_printf("hold_second->content = %d\n", *(int *)((*hold_second)->content));
	if (ra_hold_first < (ft_lstsize(*stack_a) - ra_hold_second))
	{
		*hold = *hold_first;
		return (ra_hold_first);
	}
	else
	{
		*hold = *hold_second;
		return (ra_hold_second);
	}
}

int	select_chunk_num(int stack_size)
{
	int	chunk_num;

	chunk_num = 2;
	if (stack_size > STACK_SIZE_1)
		chunk_num++;
	if (stack_size > STACK_SIZE_2)
		chunk_num++;
	if (stack_size > STACK_SIZE_3)
		chunk_num++;
	if (stack_size > STACK_SIZE_4)
		chunk_num++;
	if (stack_size > STACK_SIZE_5)
		chunk_num++;
	if (stack_size > STACK_SIZE_6)
		chunk_num++;
	if (stack_size > STACK_SIZE_7)
		chunk_num++;
	if (stack_size > STACK_SIZE_8)
		chunk_num++;
	if (stack_size > STACK_SIZE_9)
		chunk_num++;
	if (stack_size > STACK_SIZE_10)
		chunk_num++;
	return (chunk_num);
}

void	big_algorithm(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size)
{
	int		amplitude;
	int		chunk_num;
	t_list	*hold;
	int		r_count;
	int		rr_count;
	int		i;
	int		chunk_min;
	int		chunk_size;
	int		chunk_size_count;

	chunk_min = smallest(stack_a);
	amplitude = biggest(stack_a) - chunk_min + 1;
	chunk_num = select_chunk_num(stack_size);
	chunk_size = amplitude / chunk_num;
	i = 0;
	while (i < chunk_num)
	{
		chunk_size_count = chunk_size;
		while (chunk_size_count--)
		{
			ft_printf("i = %d\n", i);
			ft_printf("chunk_num = %d\n", chunk_num);
			ft_printf("chunk_size = %d\n", chunk_size);
			ft_printf("chunk_size_count = %d\n", chunk_size_count);
			r_count = compute_ra_and_hold(stack_a, chunk_min + i * chunk_size, chunk_min + (i + 1) * chunk_size - 1, &hold);
			rr_count = ft_lstsize(*stack_a) - r_count;
			if (r_count <= rr_count)
			{
				while (r_count--)
					ra(stack_a, stack_b, stack_o);
					//ra(stack_a, stack_o);
			}
			else
			{
				while (rr_count--)
					rra(stack_a, stack_b, stack_o);
					//rra(stack_a, stack_o);
			}
			if (ft_lstsize(*stack_b))
			{
				ft_printf("hold = %p\n", hold);
				ft_printf("hold->content = %d\n", *(int *)(hold->content));
				r_count = compute_r_distance(stack_b, hold);
				ft_printf("hello there\n");
				rr_count = ft_lstsize(*stack_b) - r_count;
				if (r_count <= rr_count)
				{
					while (r_count--)
						rb(stack_a, stack_b, stack_o);
						//rb(stack_b, stack_o);
				}
				else
				{
					while (rr_count--)
						rrb(stack_a, stack_b, stack_o);
						//rrb(stack_b, stack_o);
				}
			}
			pb(stack_b, stack_a, stack_o);
		}
		i++;
	}
}
