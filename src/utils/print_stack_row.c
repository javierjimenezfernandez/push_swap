/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:45:07 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 11:55:52 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ab_row(t_list *node_a, t_list *node_b)
{
	print_index(node_a);
	ft_printf("\t");
	print_value(node_a);
	ft_printf("\t");
	print_cost(node_a);
	ft_printf("\t|\t");
	print_index(node_b);
	ft_printf("\t");
	print_value(node_b);
	ft_printf("\t");
	print_cost(node_b);
	ft_printf("\n");
}

void	print_a_row(t_list *node_a)
{
	print_index(node_a);
	ft_printf("\t");
	print_value(node_a);
	ft_printf("\t");
	print_cost(node_a);
	ft_printf("\t|\t");
	ft_printf("\t");
	ft_printf("\t\n");
}

void	print_b_row(t_list *node_b)
{
	ft_printf("\t");
	ft_printf("\t\t|\t");
	print_index(node_b);
	ft_printf("\t");
	print_value(node_b);
	ft_printf("\t");
	print_cost(node_b);
	ft_printf("\n");
}

void	print_row(t_list **node_a, t_list **node_b)
{
	if (*node_a && *node_b)
	{
		print_ab_row(*node_a, *node_b);
		*node_a = (*node_a)->next;
		*node_b = (*node_b)->next;
	}
	else if (*node_a && !(*node_b))
	{
		print_a_row(*node_a);
		*node_a = (*node_a)->next;
	}
	else if (!(*node_a) && *node_b)
	{
		print_b_row(*node_b);
		*node_b = (*node_b)->next;
	}
}
