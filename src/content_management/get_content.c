/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:55:37 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 11:00:26 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *node)
{
	return (((t_content *)(node->content))->index);
}

int	get_cost(t_list *node)
{
	return (((t_content *)(node->content))->cost);
}

int	get_value(t_list *node)
{
	return (((t_content *)(node->content))->value);
}
