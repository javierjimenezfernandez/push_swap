/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:06:14 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/22 16:18:06 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ps_error_t	is_bigger_than_int(char *str, int len)
{
	if (str[0] == '+')
	{
		str++;
		len--;
	}
	if ( ((len == 10) && (ft_strncmp(str, "2147483648", len) > 0)) || \
	     ((len > 10) && (ft_strncmp(str, "-2147483649", len) > 0)) )
		return (PS_ERROR);
	return (PS_OK);
}

ps_error_t	is_duplicated(char *str1, char *str2)
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

ps_error_t	input_control(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = 0;
		k = i + 1;
		if (argv[i][j] == '+' || argv[i][j] =='-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (PS_ERROR);
			j++;
		}
		if (is_bigger_than_int(argv[i], j))
			return (PS_ERROR);
		while (k < argc)
		{
			if (is_duplicated(argv[i], argv[k]))
				return (PS_ERROR);
			k++;
		}
		i++;
	}
	return (PS_OK);
}
