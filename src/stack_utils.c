/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:45:23 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/12 02:08:03 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*dummy_node;

	dummy_node = NULL;
	stack_a = &dummy_node;
	stack_b = &dummy_node;
}

void	free_stack(t_list **stack)
{
	ft_lstclear(stack, free);
	free(stack);
}

void	free_stacks(t_list **stack_a, t_list **stack_b, t_list **stack_o)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_stack(stack_o);
}

t_list	*return_second2last(t_list **stack)
{
	t_list	*i;

	if (!stack || !(*stack))
		return (NULL);
	i = *stack;
	while ((i->next)->next)
		i = i->next;
	return (i);
}

void	print_stack(t_list **stack)
{
	t_list	*i;

	i = *stack;
	while (i)
	{
		ft_printf("%d\n", *(int *)(i->content));
		i = i->next;
	}
}

void	print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*i;
	t_list	*j;

	i = *stack_a;
	j = *stack_b;
	ft_printf("\tstack_a\t|\tstack_b\t\n");
	while (i || j)
	{
		if (i && j)
		{
			ft_printf("\t%d\t|\t%d\t\n", *(int *)(i->content), \
						*(int *)(j->content));
			i = i->next;
			j = j->next;
		}
		else if (i && !j)
		{
			ft_printf("\t%d\t|\t\t\n", *(int *)(i->content));
			i = i->next;
		}
		else if (!i && j)
		{
			ft_printf("\t\t|\t%d\t\n", *(int *)(j->content));
			j = j->next;
		}
	}
}

void	add_operation(t_list **stack_o, char *op_name)
{
	t_list	*new_op;

	new_op = ft_lstnew(ft_strdup(op_name));
	if (!new_op)
		return ;
	ft_lstadd_back(stack_o, new_op);
}

void	print_operations(t_list **stack)
{
	t_list	*i;

	i = *stack;
	while (i)
	{
		ft_printf("%s\n", (char *)(i->content));
		i = i->next;
	}
}
