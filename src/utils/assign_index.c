/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:27:42 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 20:22:25 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*node_w_content(t_list *i)
{
	t_list		*new_node;
	t_content	*new_content;

	new_content = (t_content *)malloc(sizeof(t_content));
	if (!new_content)
		return (NULL);
	new_node = ft_lstnew(new_content);
	if (!new_node)
	{
		free(new_content);
		return (NULL);
	}
	set_content(new_node, INIT_INDEX, INIT_COST, *(int *)(i->content));
	return (new_node);
}

t_ps_error	add_content(t_list **stack)
{
	t_list		*new_stack;
	t_list		*i;
	t_list		*new_node;

	new_stack = NULL;
	i = *stack;
	while (i)
	{
		new_node = node_w_content(i);
		if (!new_node)
		{
			free_stack(&new_stack, free);
			return (PS_MALLOC_FAIL);
		}
		ft_lstadd_back(&new_stack, new_node);
		i = i->next;
	}
	free_stack(stack, free);
	*stack = new_stack;
	return (PS_OK);
}

t_list	*find_next(t_list **stack, t_list *candidate, t_list *prev_candidate)
{
	t_list	*i;

	i = *stack;
	while (i)
	{
		if ((get_value(prev_candidate) < get_value(i)) && \
			(get_value(i) < get_value(candidate)))
			candidate = i;
		i = i->next;
	}
	return (candidate);
}

t_ps_error	assign_index(t_list **stack)
{
	t_list	*i;
	t_list	*biggest;
	int		index;
	t_list	*candidate;
	t_list	*prev_candidate;

	if (add_content(stack) == PS_MALLOC_FAIL)
		return (PS_MALLOC_FAIL);
	index = 0;
	prev_candidate = get_smallest(stack);
	set_index(prev_candidate, index);
	index++;
	biggest = get_biggest(stack);
	i = *stack;
	while (i->next)
	{
		candidate = find_next(stack, biggest, prev_candidate);
		set_index(candidate, index);
		index++;
		prev_candidate = candidate;
		i = i->next;
	}
	return (PS_OK);
}
