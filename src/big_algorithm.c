/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:20:19 by javjimen          #+#    #+#             */
/*   Updated: 2024/07/04 21:00:57 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_and_hold_first(t_list **stack, t_hold *holder, int chunk_min, int chunk_max)
{
	int		distance;
	t_list	*i;

	distance = 0;
	i = *stack;
	/* debug */
	ft_printf("in distance_and_hold_first: chunk_min = %d\n", chunk_min);
	ft_printf("in distance_and_hold_first: chunk_max = %d\n", chunk_max);
	//print_stack_w_index(stack);
	while (i)
	{
		//ft_printf("in distance_and_hold_first: hi1\n");
		if ((get_index((t_content *)(i->content)) >= chunk_min) && (get_index((t_content *)(i->content)) <= chunk_max))
		{
			//ft_printf("in distance_and_hold_first: hi2\n");
			holder->hold_first = i;
			break ;
		}
		//ft_printf("in distance_and_hold_first: hi3\n");
		distance++;
		i = i->next;
	}
	/* debug */
	//ft_printf("in distance_and_hold_first: hi4\n");
	ft_printf("in distance_and_hold_first: hold_first->content->index = %d\n", get_index((t_content *)((holder->hold_first)->content)));
	ft_printf("in distance_and_hold_first: hold_first->content->value = %d\n", get_value((t_content *)((holder->hold_first)->content)));
	ft_printf("in distance_and_hold_first: distance = %d\n", distance);
	return (distance);
}

int	distance_and_hold_second(t_list **stack, t_hold *holder, int chunk_min, int chunk_max)
{
	int		count;
	int		distance;
	int		stack_size;
	t_list	*i;

	count = 0;
	distance = count;
	i = *stack;
	/* debug */
	ft_printf("in distance_and_hold_second: chunk_min = %d\n", chunk_min);
	ft_printf("in distance_and_hold_second: chunk_max = %d\n", chunk_max);
	stack_size = ft_lstsize(*stack);
	ft_printf("in distance_and_hold_second: stack size = %d\n", stack_size);
	while (i)
	{
		if ((get_index((t_content *)(i->content)) >= chunk_min) && (get_index((t_content *)(i->content)) <= chunk_max))
		{
			holder->hold_second = i;
			distance = count;
			/* debug */
			//ft_printf("in distance_and_hold_second: hold_second->content = %d\n", *(int *)((holder->hold_second)->content));
			//ft_printf("in distance_and_hold_second: distance = %d\n", distance);
			/* The following if-break is necessary because some sort of compiler
			optimization that assigns hold_second in the last place just before
			leaving the while loop */
			if (distance == (stack_size - 1))
			{
				/* debug */
				ft_printf("in distance_and_hold_second: enters break\n");
				break ;
			}
		}
		count++;
		i = i->next;
	}
	/* debug */
	ft_printf("in distance_and_hold_second: hold_second->content->index = %d\n", get_index((t_content *)((holder->hold_second)->content)));
	ft_printf("in distance_and_hold_second: hold_second->content->value = %d\n", get_value((t_content *)((holder->hold_second)->content)));
	ft_printf("in distance_and_hold_second: distance = %d\n", distance);
	return (distance);
}

int	compute_ra_and_hold(t_list **stack_a, int chunk_min_index, int chunk_max_index, t_list *hold)
{
	int		ra_hold_first;
	int		ra_hold_second;
	t_hold	holder;

	holder.hold_first = NULL;
	holder.hold_second = NULL;
	/* debug */
	print_stack_w_index(stack_a);
	ra_hold_first = distance_and_hold_first(stack_a, &holder, chunk_min_index, chunk_max_index);
	ra_hold_second = distance_and_hold_second(stack_a, &holder, chunk_min_index, chunk_max_index);
	/* debug */
	ft_printf("in compute_ra_and_hold: { ra_hold_first = %d,\t", ra_hold_first);
	ft_printf("hold_first->content->\t(index = %d, value = %d) }\n", get_index((t_content *)(holder.hold_first->content)), get_value((t_content *)(holder.hold_first->content)));
	ft_printf("in compute_ra_and_hold: { ra_hold_second = %d,\t", ra_hold_second);
	ft_printf("hold_second->content->\t(index = %d, value = %d) }\n", get_index((t_content *)(holder.hold_second->content)), get_value((t_content *)(holder.hold_second->content)));
	if (ra_hold_first < (ft_lstsize(*stack_a) - ra_hold_second))
	{
		*hold = *(holder.hold_first);
		return (ra_hold_first);
	}
	else
	{
		*hold = *(holder.hold_second);
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

void	prepare_b_for_pa(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o)
{
	int		r_count;
	int		rr_count;

	r_count = r_distance_to_node(stack_b, get_biggest(stack_b));
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

void	pa_all(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size)
{
	while (stack_size--)
		pa(stack_a, stack_b, stack_o);
}

t_ps_error	big_algorithm(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size)
{
	//int		amplitude;
	int		chunk_num;
	t_list	hold;
	int		r_count;
	int		rr_count;
	int		i;
	//int		chunk_min;
	int		chunk_size;
	int		chunk_size_rem;
	int		chunk_size_count;
	int		first_chunk_flag;

	/* implementar la logica usando assign_index */
	if (assign_index(stack_a) == PS_MALLOC_FAIL)
	{
		free_stacks(stack_a, stack_b, stack_o, free);
		return (PS_MALLOC_FAIL);
	}
	/* debug */
	//print_stack_w_index(stack_a);
	// chunk_min = smallest(stack_a);
	// amplitude = biggest(stack_a) - chunk_min + 1;
	chunk_num = select_chunk_num(stack_size);
	//chunk_size = amplitude / chunk_num;
	chunk_size = stack_size / chunk_num;
	chunk_size_rem = stack_size % chunk_num;
	first_chunk_flag = 0;
	/* debug */
	ft_printf("in big_algorithm: initial chunk_size_rem = %d\n", chunk_size_rem);
	i = 0;
	while (i < chunk_num)
	{
		chunk_size_count = chunk_size;
		/*if (chunk_size_rem-- > 0)
			chunk_size_count++;*/
		if (i == 0)
			chunk_size_count += chunk_size_rem;
		while (chunk_size_count--)
		{
			/* debug */
			ft_printf("in big_algorithm: i = %d\n", i);
			ft_printf("in big_algorithm: chunk_num = %d\n", chunk_num);
			ft_printf("in big_algorithm: stack_size = %d\n", stack_size);
			ft_printf("in big_algorithm: chunk_size = %d\n", chunk_size);
			ft_printf("in big_algorithm: chunk_size_rem = %d\n", chunk_size_rem);
			ft_printf("in big_algorithm: chunk_size_count = %d\n", chunk_size_count);
			//print_stack_w_index(stack_a);
			r_count = compute_ra_and_hold(stack_a, i * chunk_size + chunk_size_rem * first_chunk_flag, (i + 1) * chunk_size + chunk_size_rem - 1, &hold);
			rr_count = ft_lstsize(*stack_a) - r_count;
			/* debug */
			ft_printf("in big_algorithm: hold = %p\n", hold);
				ft_printf("in big_algorithm: hold->content-> (index = %d, value = %d)\n", get_index((t_content *)(hold.content)), get_value((t_content *)(hold.content)));
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
				/* debug */
				ft_printf("in big_algorithm: hold = %p\n", hold);
				ft_printf("in big_algorithm: hold->content-> (index = %d, value = %d)\n", get_index((t_content *)(hold.content)), get_value((t_content *)(hold.content)));
				/* next function doesn't work properly because is meant for an "int *content"
				it's time to migrate small and middle algorithm functions for the new content type*/
				r_count = compute_r_before_push(stack_b, &hold);
				ft_printf("in big_algorithm: r_count brefore push = %d\n", r_count);
				/* debug */
				//ft_printf("in big_algorithm: hello there\n");
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
			pb(stack_a, stack_b, stack_o);
		}
		first_chunk_flag = 1;
		i++;
	}
	prepare_b_for_pa(stack_a, stack_b, stack_o);
	pa_all(stack_a, stack_b, stack_o, stack_size);
	return (PS_OK);
}
