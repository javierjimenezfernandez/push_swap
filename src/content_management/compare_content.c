/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:03:32 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 11:03:47 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_values(t_list *node_a, t_list *node_b)
{
	return (get_value(node_a) - get_value(node_b));
}

int	compare_index(t_list *node_a, t_list *node_b)
{
	return (get_index(node_a) - get_index(node_b));
}

int	compare_index_w_int(t_list *node_a, int index)
{
	return (get_index(node_a) - index);
}

int	compare_cost(t_list *node_a, t_list *node_b)
{
	return (get_cost(node_a) - get_cost(node_b));
}
