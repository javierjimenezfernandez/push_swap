/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:27:42 by javjimen          #+#    #+#             */
/*   Updated: 2024/07/02 19:21:13 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_error	add_index(t_list **stack)
{
	t_list		*new_stack;
	t_list		*i;
	t_list		*new_node;
	t_content	*new_content;

	new_stack = (t_list *)malloc(sizeof(t_list));
	if (!new_stack)
		return (PS_MALLOC_FAIL);
	new_stack = NULL;
	i = *stack;
	while (i)
	{
		new_content = (t_content *)malloc(sizeof(t_content));
		if (init_content(new_content) == PS_MALLOC_FAIL)
		{
			free_stack(&new_stack, free_content);
			return (PS_MALLOC_FAIL);
		}
		set_value(new_content, (int *)(i->content));
		new_node = ft_lstnew(new_content);
		ft_lstadd_back(&new_stack, new_node);
		i = i->next;
	}
	free_stack(stack, free);
	*stack = new_stack;
	/* debug */
	//print_stack_w_index(*stack);
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
	prev_candidate = NULL;
	/* debug */
	//print_stack_w_index(stack);
	prev_candidate = get_smallest(stack);
	/* debug */
	ft_printf("in assign_index: prev_candidate->content = %d\n", get_value((t_content *)(prev_candidate->content)));
	set_index(prev_candidate->content, &index);
	/* debug */
	ft_printf("in assign_index: prev_candidate->index = %d\n", get_index((t_content *)(prev_candidate->content)));
	//print_stack_w_index(stack);
	candidate = get_biggest(stack);
	index++;
	i = *stack;
	candidate = i;
	while (i)
	{
		j = *stack;
		/* debería encontrar la forma de optimizar esto con una variable en vez
		de llamar todo el tiempo a esta función?*/
		candidate = get_biggest(stack);
		/* Este if es para arreglar el caso de que el primer número es el más
		pequeño. Si esto ocurriera, entonces a ese valor le sobreescribirá el
		índice a 1 en vez de 0 así que los índices irán de 1 a n en vez de 0
		a n-1 donde n es el tamaño del stack. La única posibilidad de entrar
		en el if es en la primera vuelta, ya que candidate y prev_candidate
		nunca pueden ser iguales dentro de este bucle */
		/*if (compare_values(candidate, prev_candidate) == 0)
		{
			ft_printf("in assign_index: hi\n");
			index--;
		}*/
		while (j)
		{
			if ((compare_values(j, prev_candidate) > 0) \
				&& (compare_values(j, candidate) < 0))
				candidate = j;
			j = j->next;
		}
		if (get_index((t_content *)(candidate->content)) == -1)
		{
			set_index((t_content *)(candidate->content), &index);
			/* debug */
			ft_printf("in assign_index: set index %d for %d\n", get_index((t_content *)(candidate->content)), get_value((t_content *)(candidate->content)));
			index++;
			prev_candidate = candidate;
		}
		i = i->next;
	}
	//print_stack_w_index(stack);
	return (PS_OK);
}
