/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:45:23 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/12 21:06:37 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	smallest(t_list **stack)
{
	int		candidate;
	t_list	*i;

	candidate = *(int *)((*stack)->content);
	i = (*stack)->next;
	while (i)
	{
		if (*(int *)(i->content) < candidate)
			candidate = *(int *)(i->content);
		i = i->next;
	}
	return (candidate);
}

int	distance_to_smallest(t_list **stack)
{
	int		candidate;
	int		distance;
	int		count;
	t_list	*i;

	count = 0;
	distance = count;
	candidate = *(int *)((*stack)->content);
	i = (*stack)->next;
	count++;
	while (i)
	{
		if (*(int *)(i->content) < candidate)
		{
			candidate = *(int *)(i->content);
			distance = count;
		}
		count++;
		i = i->next;
	}
	return (distance);
}

int	distance_and_smallest(t_list **stack, int *smallest)
{
	int		distance;
	int		count;
	t_list	*i;

	count = 0;
	distance = count;
	*smallest = *(int *)((*stack)->content);
	i = (*stack)->next;
	count++;
	while (i)
	{
		if (*(int *)(i->content) < *smallest)
		{
			*smallest = *(int *)(i->content);
			distance = count;
		}
		count++;
		i = i->next;
	}
	return (distance);
}

int	biggest(t_list **stack)
{
	int		candidate;
	t_list	*i;

	candidate = *(int *)((*stack)->content);
	i = (*stack)->next;
	while (i)
	{
		if (*(int *)(i->content) > candidate)
			candidate = *(int *)(i->content);
		i = i->next;
	}
	return (candidate);
}

int	distance_to_biggest(t_list **stack)
{
	int		candidate;
	int		distance;
	int		count;
	t_list	*i;

	count = 0;
	distance = count;
	candidate = *(int *)((*stack)->content);
	i = (*stack)->next;
	count++;
	while (i)
	{
		if (*(int *)(i->content) > candidate)
		{
			candidate = *(int *)(i->content);
			distance = count;
		}
		count++;
		i = i->next;
	}
	return (distance);
}

int	distance_and_biggest(t_list **stack, int *biggest)
{
	int		distance;
	int		count;
	t_list	*i;

	count = 0;
	distance = count;
	*biggest = *(int *)((*stack)->content);
	i = (*stack)->next;
	count++;
	while (i)
	{
		if (*(int *)(i->content) > *biggest)
		{
			*biggest = *(int *)(i->content);
			distance = count;
		}
		count++;
		i = i->next;
	}
	return (distance);
}
