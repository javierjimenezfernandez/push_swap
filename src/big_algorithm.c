/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:20:19 by javjimen          #+#    #+#             */
/*   Updated: 2024/08/06 21:15:10 by javjimen         ###   ########.fr       */
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

int	compute_ra_and_hold(t_list **stack_a, t_list **stack_b, int chunk_min_index, int chunk_max_index, t_list *hold)
{
	int		ra_hold_first;
	int		ra_hold_second;
	int		rb_hold_first;
	int		rb_hold_second;
	t_hold	holder;

	holder.hold_first = NULL;
	holder.hold_second = NULL;
	/* debug */
	print_stack_w_index(stack_a);
	ra_hold_first = distance_and_hold_first(stack_a, &holder, chunk_min_index, chunk_max_index);
	ra_hold_second = distance_and_hold_second(stack_a, &holder, chunk_min_index, chunk_max_index);
	rb_hold_first = compute_r_before_push(stack_b, holder.hold_first);
	rb_hold_second = compute_r_before_push(stack_b, holder.hold_second);
	/* debug */
	ft_printf("in compute_ra_and_hold: { ra_hold_first = %d, rb_hold_first = %d,\t", ra_hold_first, rb_hold_first);
	ft_printf("hold_first->content->\t(index = %d, value = %d) }\n", get_index((t_content *)(holder.hold_first->content)), get_value((t_content *)(holder.hold_first->content)));
	ft_printf("in compute_ra_and_hold: { ra_hold_second = %d, rb_hold_second = %d,\t", ra_hold_second, rb_hold_second);
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

int	compute_chunk_quantity(int stack_size)
{
	int	chunk_num;

	chunk_num = (ft_sqrt(stack_size - 1) / 2) + 1;
	if (chunk_num % 2 != 0)
		chunk_num--;
	/*chunk_num = 2;
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
		chunk_num++;*/
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

int	is_in_chunk(t_list	*node, int chunk_min_index, int chunk_max_index)
{
	if (compare_index_value(node, chunk_min_index) >= 0 && \
		compare_index_value(node, chunk_max_index) <= 0)
		return (1);
	else
		return (0);
}

void	assign_cost_by_chunk(t_list **stack_a, int chunk_min_index, \
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
			assign_smallest(&cost, &ra_count, &rra_count);
			cost += rb_count;
			set_cost((t_content *)(i->content), &cost);
			ft_printf("in assign_cost_by_chunk: i->content->cost = ");
			print_cost((t_content *)(i->content));
			ft_printf("\n");
		}
		ra_count++;
		i = i->next;
	}
}

// esta funcion podría ser void (esperar a tener todo el códgio por si me viene bien aún)
t_list	*get_cheapest(t_list **stack, int *ra_count)
{
	t_list	*i;
	int		count;
	t_list	*cheapest;

	cheapest = *stack;
	count = 0;
	i = *stack;
	while (i)
	{
		if (get_cost((t_content *)(i->content)) >= 0)
		{
			cheapest = i;
			*ra_count = count;
			break ;
		}
		count++;
		i = i->next;
	}
	count = 0;
	i = *stack;
	while (i)
	{
		/*ft_printf("in find_cheapest: i->content->cost = ");
		print_cost((t_content *)(cheapest->content));
		ft_printf("\n");*/
		if (get_cost((t_content *)(i->content)) >= 0)
		{
			//ft_printf("in find_cheapest: hi\n ");
			if (compare_cost(i, cheapest) < 0)
			{
				//ft_printf("in find_cheapest: hi2\n ");
				cheapest = i;
				*ra_count = count;
			}
		}
		count++;
		i = i->next;
	}
	ft_printf("in get_cheapest: cheapest->content->cost = ");
	print_cost((t_content *)(cheapest->content));
	ft_printf("\n");
	if (get_cost((t_content *)(cheapest->content)) == -1)
		exit(1);
	return (cheapest);
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
	int		chunk_qty;
	int		chunk_size;
	int		chunk_size_count;
	int		i;
	//int		j;

	chunk_qty = compute_chunk_quantity(stack_size);
	chunk_size = stack_size / chunk_qty;
	if ((stack_size % chunk_qty) != 0)
		chunk_size += 1;
	/* debug */
	ft_printf("in big_algorithm: chunk_num = %d\n", chunk_qty);
	ft_printf("in big_algorithm: chunk_size = %d\n", chunk_size);
	i = 0;
	//j = chunk_qty - 1;
	/* me falta pushear un primer elemento del primer chunk o último chunk para
	empezar y controlar que paso el primer y último chunk a la vez */
	//while (i < j)
	while (2 * i < chunk_qty - 1)
	{
		chunk_size_count = chunk_size * 2;
		while (chunk_size_count-- && *stack_a)
		{
			// computo coste primer chunk
			assign_cost_by_chunk(stack_a, i * chunk_size, (i + 1) * chunk_size - 1, 0);
			// computo coste ultimo chunk
			//assign_cost_by_chunk(stack_a, j * chunk_size, (j + 1) * chunk_size - 1, 1);
			assign_cost_by_chunk(stack_a, stack_size - 1 - ((i + 1) * chunk_size - 1), stack_size - 1 - (i * chunk_size), 1);
			// paso el que tenga un coste menor
			//if (is_in_chunk(pb_cheapest(stack_a, stack_b, stack_o), j * chunk_size, (j + 1) * chunk_size - 1))
			if (is_in_chunk(pb_cheapest(stack_a, stack_b, stack_o), stack_size - 1 - ((i + 1) * chunk_size - 1), stack_size - 1 - (i * chunk_size)))
				rb(stack_a, stack_b, stack_o);
		}
		i++;
		//j--;
	}
	return (PS_OK);
}

t_ps_error	big_algorithm(t_list **stack_a, t_list **stack_b, \
							t_list **stack_o, int stack_size)
{
	if (assign_index(stack_a) == PS_MALLOC_FAIL)
	{
		free_stacks(stack_a, stack_b, stack_o, free);
		return (PS_MALLOC_FAIL);
	}
	pb_chunks(stack_a, stack_b, stack_o, stack_size);

	return (PS_OK);
}
