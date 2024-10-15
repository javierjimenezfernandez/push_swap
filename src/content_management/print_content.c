/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:04:05 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 11:04:19 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_index(t_list *node)
{
	ft_printf("%d", ((t_content *)(node->content))->index);
}

void	print_value(t_list *node)
{
	ft_printf("%d", ((t_content *)(node->content))->value);
}

void	print_cost(t_list *node)
{
	ft_printf("%d", ((t_content *)(node->content))->cost);
}
