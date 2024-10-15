/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:02:54 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 11:26:46 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *node, int index)
{
	((t_content *)(node->content))->index = index;
}

void	set_cost(t_list *node, int cost)
{
	((t_content *)(node->content))->cost = cost;
}

void	set_value(t_list *node, int value)
{
	((t_content *)(node->content))->value = value;
}

void	set_content(t_list *node, int index, int cost, int value)
{
	set_index(node, index);
	set_cost(node, cost);
	set_value(node, value);
}
