/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:27:42 by javjimen          #+#    #+#             */
/*   Updated: 2024/06/28 21:20:29 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_error	add_index(t_list **stack)
{
	t_list		**new_stack;
	t_list		*i;
	t_list		*new_node;
	t_content	*new_content;

	new_stack = (t_list **)malloc(sizeof(t_list *));
	if (!new_stack)
		return (PS_MALLOC_FAIL);
	*new_stack = NULL;
	i = *stack;
	while (i)
	{
		new_content = (t_content *)malloc(sizeof(t_content));
		if (init_content(new_content) == PS_MALLOC_FAIL)
		{
			free_stack(new_stack, free_content);
			return (PS_MALLOC_FAIL);
		}
		set_value(new_content, (int *)(i->content));
		new_node = ft_lstnew(new_content);
		ft_lstadd_back(new_stack, new_node);
		i = i->next;
	}
	free_stack(stack, free);
	stack = new_stack;
	return (PS_OK);
}

t_ps_error	assign_index(t_list **stack)
{
	t_list	*i;
	t_list	*j;
	int		index;
	t_list	*candidate;
	t_list	*prev_candidate;

	/* ojo: hay que hacer un free stacks normal con free en el momento
	que se vuelve de esta función */
	if (add_index(stack) == PS_MALLOC_FAIL)
		return (PS_MALLOC_FAIL);
	index = 0;
	prev_candidate = get_smallest(stack);
	set_index(prev_candidate->content, &index);
	index++;
	i = *stack;
	while (i)
	{
		j = i;
		candidate = j;
		/* Este if es para arreglar el caso de que el primer número es el más
		pequeño. Si esto ocurriera, entonces a ese valor le sobreescribirá el
		índice a 1 en vez de 0 así que los índices irán de 1 a n en vez de 0
		a n-1 donde n es el tamaño del stack. La única posibilidad de entrar
		en el if es en la primera vuelta, ya que candidate y prev_candidate
		nunca pueden ser iguales dentro de este bucle */
		if (compare_values(candidate, prev_candidate) == 0)
			index--;
		while (j)
		{
			if ((compare_values(j, prev_candidate) > 0) \
				&& (compare_values(j, candidate) < 0))
				candidate = j;
			j = j->next;
		}
		set_index(candidate->content, &index);
		index++;
		prev_candidate = candidate;
		i = i->next;
	}
	return (PS_OK);
}
