/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:51:00 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/07 17:19:24 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_error	parse_input(t_list **lst)
{
	t_list	*i;
	int		*atoi_argv_ptr;

	if (!lst)
		return (PS_ERROR);
	i = *lst;
	while (i)
	{
		atoi_argv_ptr = (int *)malloc(sizeof(int));
		if (!atoi_argv_ptr)
			return (PS_ERROR);
		*atoi_argv_ptr = ft_atoi(i->content);
		free(i->content);
		i->content = atoi_argv_ptr;
		i = i->next;
	}
	return (PS_OK);
}
