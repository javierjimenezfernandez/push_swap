/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:45:23 by javjimen          #+#    #+#             */
/*   Updated: 2024/08/07 18:11:25 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack, void (*del)(void *))
{
	ft_lstclear(stack, del);
	// ojo cuidado con este free que estaba comentado por algo:
	//free(stack);
}

void	free_stacks(t_list **stack_a, t_list **stack_b, t_list **stack_o, void (*del)(void *))
{
	free_stack(stack_a, del);
	free_stack(stack_b, del);
	free_stack(stack_o, free);
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

/* ojo porque los get y set no me son tan útiles si tengo que pasarle como
argumento este chorizo : "(t_content *)(nodo->content)". Sería mejor poder
pasarles únicamente el nodo y que la función ya castease internamente para
devolver el return pedido */

int	get_index(t_content *content)
{
	return(*(int *)(content->index));
}

int	get_cost(t_content *content)
{
	return(*(int *)(content->cost));
}


int	get_value(t_content *content)
{
	return(*(int *)(content->value));
}

void	set_index(t_content *content, int *index)
{
	*(content->index) = *index;
}

void	set_cost(t_content *content, int *cost)
{
	*(content->cost) = *cost;
}


void	set_value(t_content *content, int *value)
{
	*(content->value) = *value;
}

void	free_content(void *content)
{
	free(((t_content *)content)->index);
	free(((t_content *)content)->cost);
	free(((t_content *)content)->value);
	free(content);
}

void	print_index(t_content *content)
{
	ft_printf("%d", *(int *)(content->index));
}

void	print_value(t_content *content)
{
	ft_printf("%d", *(int *)(content->value));
}

void	print_cost(t_content *content)
{
	ft_printf("%d", *(int *)(content->cost));
}

void	print_stack_w_index(t_list **stack)
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

void	print_stacks_w_index(t_list **stack_a, t_list **stack_b)
{
	t_list	*i;
	t_list	*j;

	i = *stack_a;
	j = *stack_b;
	ft_printf("\tstack_a\t\t|\t\tstack_b\t\n");
	ft_printf("index\tvalue\tcost\t|\tindex\tvalue\tcost\n");
	while (i || j)
	{
		if (i && j)
		{
			print_index((t_content *)(i->content));
			ft_printf("\t");
			print_value((t_content *)(i->content));
			ft_printf("\t");
			print_cost((t_content *)(i->content));
			ft_printf("\t|\t");
			print_index((t_content *)(j->content));
			ft_printf("\t");
			print_value((t_content *)(j->content));
			ft_printf("\t");
			print_cost((t_content *)(j->content));
			ft_printf("\n");
			i = i->next;
			j = j->next;
		}
		else if (i && !j)
		{
			print_index((t_content *)(i->content));
			ft_printf("\t");
			print_value((t_content *)(i->content));
			ft_printf("\t");
			print_cost((t_content *)(i->content));
			ft_printf("\t|\t");
			ft_printf("\t");
			ft_printf("\t\n");
			i = i->next;
		}
		else if (!i && j)
		{
			ft_printf("\t");
			ft_printf("\t\t|\t");
			print_index((t_content *)(j->content));
			ft_printf("\t");
			print_value((t_content *)(j->content));
			ft_printf("\t");
			print_cost((t_content *)(j->content));
			ft_printf("\n");
			j = j->next;
		}
	}
}

t_list	*get_smallest(t_list **stack)
{
	t_list	*i;
	t_list	*candidate;

	i = *stack;
	candidate = *stack;
	/* debug */
	//ft_printf("in get_smallest: hi1\n");
	//ft_printf("in get_smallest: content = %p\n", (i->content));
	//ft_printf("in get_smallest: content->value = %d\n", get_value((t_content *)(i->content)));
	i = i->next;
	/* debug */
	//ft_printf("in get_smallest: hi2\n");
	//ft_printf("in get_smallest: content->value = %d\n", get_value((t_content *)(i->content)));
	while (i)
	{
		if (get_value((t_content *)(i->content)) < get_value((t_content *)((candidate)->content)))
			candidate = i;
		i = i->next;
	}
	/* debug */
	//ft_printf("in get_smallest: hi3\n");
	//ft_printf("in get_smallest: content->value = %d\n", get_value((t_content *)((candidate)->content)));
	return (candidate);
}

t_list	*get_biggest(t_list **stack)
{
	t_list	*i;
	t_list	*candidate;

	i = *stack;
	candidate = *stack;
	/* debug */
	//ft_printf("in get_bigest: hi1\n");
	//ft_printf("in get_bigest: content = %p\n", (i->content));
	//ft_printf("in get_bigest: content->value = %d\n", get_value((t_content *)(i->content)));
	i = i->next;
	/* debug */
	//ft_printf("in get_bigest: hi2\n");
	//ft_printf("in get_bigest: content->value = %d\n", get_value((t_content *)(i->content)));
	while (i)
	{
		if (get_value((t_content *)(i->content)) > get_value((t_content *)((candidate)->content)))
			candidate = i;
		i = i->next;
	}
	/* debug */
	//ft_printf("in get_bigest: hi3\n");
	//ft_printf("in get_bigest: content->value = %d\n", get_value((t_content *)((candidate)->content)));
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
		if (get_value((t_content *)(i->content)) == get_value((t_content *)(node->content)))
			break ;
		r_count++;
		i = i->next;
	}
	return (r_count);
}

int	compute_r_before_push(t_list **stack, t_list *node)
{
	int		r_count;
	t_list	*i;

	i = get_biggest(stack);
	r_count = r_distance_to_node(stack, i);
	while (i)
	{
		if (get_value((t_content *)(i->content)) < get_value((t_content *)(node->content)))
			return (r_count);
		r_count++;
		i = i->next;
	}
	r_count = 0;
	i = *stack;
	while (i)
	{
		if (get_value((t_content *)(i->content)) < get_value((t_content *)(node->content)))
			break ;
		r_count++;
		i = i->next;
	}
	if (r_count == ft_lstsize(*stack))
	{
		if (r_count > r_distance_to_node(stack, get_biggest(stack)))
			r_count = r_distance_to_node(stack, get_biggest(stack));
	}
	return (r_count);
}

int	compare_values(t_list *node_a, t_list *node_b)
{
	return (get_value((t_content *)(node_a->content)) - get_value((t_content *)(node_b->content)));
}

int	compare_index(t_list *node_a, t_list *node_b)
{
	return (get_index((t_content *)(node_a->content)) - get_index((t_content *)(node_b->content)));
}

int	compare_index_value(t_list *node_a, int index_value)
{
	return (get_index((t_content *)(node_a->content)) - index_value);
}

int	compare_cost(t_list *node_a, t_list *node_b)
{
	return (get_cost((t_content *)(node_a->content)) - get_cost((t_content *)(node_b->content)));
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

void	assign_biggest(int *dst, int a, int b)
{
	*dst = a;
	if (*dst < b)
		*dst = b;
}

void	assign_smallest(int *dst, int a, int b)
{
	*dst = a;
	if (*dst > b)
		*dst = b;
}

void	add_biggest(int *dst, int a, int b)
{
	if (a > b)
		*dst += a;
	else
		*dst += b;
}

void	add_smallest(int *dst, int a, int b)
{
	if (a < b)
		*dst += a;
	else
		*dst += b;
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
