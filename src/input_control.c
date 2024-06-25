/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:06:14 by javjimen          #+#    #+#             */
/*   Updated: 2024/06/25 21:02:28 by javjimen         ###   ########.fr       */
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

t_ps_error	is_duplicated(int num1, int num2)
{
	if (num1 == num2)
		return (PS_ERROR);
	return (PS_OK);
}

t_ps_error	is_format_incorrect(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (PS_ERROR);
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
		i = i->next;
	}
	parse_input (stack_a);
	i = *stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (is_duplicated(*(int *)(i->content), *(int *)(j->content)))
				return (PS_ERROR);
			j = j->next;
		}
		i = i->next;
	}
	return (PS_OK);
}
