/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:06:14 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/07 17:19:07 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_error	is_bigger_than_int(char *str, int len)
{
	if (str[0] == '+')
	{
		str++;
		len--;
	}
	if (((len == 10) && (ft_strncmp(str, MAX_INT, len) > 0)) || \
		((len > 10) && (ft_strncmp(str, MIN_INT, len) > 0)))
		return (PS_ERROR);
	return (PS_OK);
}

t_ps_error	is_duplicated(char *str1, char *str2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 >= len2)
	{
		if (ft_strncmp(str1, str2, len1) == 0)
			return (PS_ERROR);
	}
	else
	{
		if (ft_strncmp(str1, str2, len2) == 0)
			return (PS_ERROR);
	}
	return (PS_OK);
}

t_ps_error	is_format_incorrect(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (PS_ERROR);
		i++;
	}
	if (is_bigger_than_int(str, i))
		return (PS_ERROR);
	return (PS_OK);
}

t_ps_error	input_control(t_list **stack_a)
{
	t_list	*i;
	t_list	*j;

	i = *stack_a;
	while (i)
	{
		if (is_format_incorrect(i->content))
			return (PS_ERROR);
		j = i->next;
		while (j)
		{
			if (is_duplicated(i->content, j->content))
				return (PS_ERROR);
			j = j->next;
		}
		i = i->next;
	}
	return (PS_OK);
}
