/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:27:42 by javjimen          #+#    #+#             */
/*   Updated: 2024/06/27 21:06:42 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_list **stack)
{
	t_list		**new_stack;
	t_list		*i;
	t_list		*new_node;
	t_content	*new_content;

	new_stack = (t_list **)malloc(sizeof(t_list *));
	/* ¿return PS_MALLOC_FAIL?*/
	if (!new_stack)
		return ;
	*new_stack = NULL;
	i = *stack;
	while (i)
	{
		new_content = (t_content **)malloc(sizeof(t_content *));
		/* implement retroactive free to avoid leaks ¿return PS_MALLOC_FAIL?*/
		if (!new_content)
		{
			return ;
		}
		new_content->index = (int *)malloc(sizeof(int));
		/* implement retroactive free to avoid leaks ¿return PS_MALLOC_FAIL?*/
		if (!(new_content->index))
		{
			return ;
		}
		new_content->value = (int *)malloc(sizeof(int));
		/* implement retroactive free to avoid leaks ¿return PS_MALLOC_FAIL?*/
		if (!(new_content->value))
		{
			return ;
		}
		*(new_content->index) = -1;
		*(new_content->value) = *(int *)(i->content);
		new_node = ft_lstnew(new_content);
		ft_lstadd_back(new_stack, new_node);
		i = i->next;
	}
	free_stack_w_index(stack);
	stack = new_stack;
}

void	assign_index(t_list **stack)
{
	t_list	*i;
	t_list	*j;
	int		index;
	t_list	*candidate;
	t_list	*prev_candidate;

	add_index(stack);
	index = 0;
	i = *stack;
	candidate = i;
	i = i->next;
	while (i)
	{
		if (get_value(i->content) < get_value(candidate->content))
			candidate = i;
		i = i->next;
	}
	set_index(candidate->content, index);
	index++;
	prev_candidate = candidate;
	i = *stack;
	i = i->next;
	while (i)
	{
		j = i;
		candidate = j;
		while (j)
		{
			if ((get_value(prev_candidate->content) < get_value(j->content)) \
				&& (get_value(j->content) < get_value(candidate->content)));
				candidate = j;
			j = j->next;
		}
		set_index(candidate->content, index);
		index++;
		prev_candidate = candidate;
		i = i->next;
	}
}
