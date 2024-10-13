/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:45:23 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/13 14:00:28 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack, void (*del)(void *))
{
	ft_lstclear(stack, del);
}

void	free_stacks(t_list **stack_a, t_list **stack_b, t_list **stack_o, \
						void (*del)(void *))
{
	free_stack(stack_a, del);
	free_stack(stack_b, del);
	free_stack(stack_o, free);
}

// los prints meterlos igual en otro archivo ?

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

/* ojo porque los get y set no me son tan útiles si tengo que pasarle como
argumento este chorizo : "(t_content *)(nodo->content)". Sería mejor poder
pasarles únicamente el nodo y que la función ya castease internamente para
devolver el return pedido */

int	get_index(t_content *content)
{
	return (content->index);
}

int	get_cost(t_content *content)
{
	return (content->cost);
}

int	get_value(t_content *content)
{
	return (content->value);
}

void	set_index(t_content *content, int *index)
{
	content->index = *index;
}

void	set_cost(t_content *content, int *cost)
{
	content->cost = *cost;
}

void	set_value(t_content *content, int *value)
{
	content->value = *value;
}

void	print_index(t_content *content)
{
	ft_printf("%d", content->index);
}

void	print_value(t_content *content)
{
	ft_printf("%d", content->value);
}

void	print_cost(t_content *content)
{
	ft_printf("%d", content->cost);
}

void	print_stack_w_content(t_list **stack)
{
	t_list	*i;

	i = *stack;
	ft_printf("\tstack\n");
	ft_printf("index\tvalue\tcost\n");
	while (i)
	{
		print_index((t_content *)(i->content));
		ft_printf("\t");
		print_value((t_content *)(i->content));
		ft_printf("\t");
		print_cost((t_content *)(i->content));
		ft_printf("\n");
		i = i->next;
	}
}

void	print_ab_row(t_list *a, t_list *b)
{
	print_index((t_content *)(a->content));
	ft_printf("\t");
	print_value((t_content *)(a->content));
	ft_printf("\t");
	print_cost((t_content *)(a->content));
	ft_printf("\t|\t");
	print_index((t_content *)(b->content));
	ft_printf("\t");
	print_value((t_content *)(b->content));
	ft_printf("\t");
	print_cost((t_content *)(b->content));
	ft_printf("\n");
}

void	print_a_row(t_list *a)
{
	print_index((t_content *)(a->content));
	ft_printf("\t");
	print_value((t_content *)(a->content));
	ft_printf("\t");
	print_cost((t_content *)(a->content));
	ft_printf("\t|\t");
	ft_printf("\t");
	ft_printf("\t\n");
}

void	print_b_row(t_list *b)
{
	ft_printf("\t");
	ft_printf("\t\t|\t");
	print_index((t_content *)(b->content));
	ft_printf("\t");
	print_value((t_content *)(b->content));
	ft_printf("\t");
	print_cost((t_content *)(b->content));
	ft_printf("\n");
}

void	print_row(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		print_ab_row(*a, *b);
		*a = (*a)->next;
		*b = (*b)->next;
	}
	else if (*a && !(*b))
	{
		print_a_row(*a);
		*a = (*a)->next;
	}
	else if (!(*a) && *b)
	{
		print_b_row(*b);
		*b = (*b)->next;
	}
}

void	print_stacks_w_content(t_list **stack_a, t_list **stack_b)
{
	t_list	*i;
	t_list	*j;

	i = *stack_a;
	j = *stack_b;
	ft_printf("\tstack_a\t\t|\t\tstack_b\t\n");
	ft_printf("index\tvalue\tcost\t|\tindex\tvalue\tcost\n");
	while (i || j)
	{
		print_row(&i, &j);
	}
}

t_list	*get_smallest(t_list **stack)
{
	t_list	*i;
	t_list	*candidate;

	i = *stack;
	candidate = *stack;
	i = i->next;
	while (i)
	{
		if (get_value((t_content *)(i->content)) < \
			get_value((t_content *)((candidate)->content)))
			candidate = i;
		i = i->next;
	}
	return (candidate);
}

t_list	*get_biggest(t_list **stack)
{
	t_list	*i;
	t_list	*candidate;

	i = *stack;
	candidate = *stack;
	i = i->next;
	while (i)
	{
		if (get_value((t_content *)(i->content)) > \
			get_value((t_content *)((candidate)->content)))
			candidate = i;
		i = i->next;
	}
	return (candidate);
}

int	r_distance_to_node(t_list **stack, t_list *node)
{
	int		r_count;
	t_list	*i;

	r_count = 0;
	i = *stack;
	while (i)
	{
		if (get_value((t_content *)(i->content)) == \
			get_value((t_content *)(node->content)))
			break ;
		r_count++;
		i = i->next;
	}
	return (r_count);
}

int	compare_values(t_list *node_a, t_list *node_b)
{
	return (get_value((t_content *)(node_a->content)) - \
			get_value((t_content *)(node_b->content)));
}

int	compare_index(t_list *node_a, t_list *node_b)
{
	return (get_index((t_content *)(node_a->content)) - \
			get_index((t_content *)(node_b->content)));
}

int	compare_index_value(t_list *node_a, int index_value)
{
	return (get_index((t_content *)(node_a->content)) - index_value);
}

int	compare_cost(t_list *node_a, t_list *node_b)
{
	return (get_cost((t_content *)(node_a->content)) - \
			get_cost((t_content *)(node_b->content)));
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

int	ft_max2(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_max3(int a, int b, int c)
{
	if (a >= b)
	{
		if (a >= c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b >= c)
			return (b);
		else
			return (c);
	}
}

int	ft_min2(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_min3(int a, int b, int c)
{
	if (a <= b)
	{
		if (a <= c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b <= c)
			return (b);
		else
			return (c);
	}
}

int	ft_sqrt(int nb)
{
	int	sq;

	sq = 1;
	while (sq < (nb / sq))
		sq++;
	if ((sq * sq) > nb)
		return (sq - 1);
	return (sq);
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
