/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:10:23 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/15 11:10:48 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max2(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_max3(int a, int b, int c)
{
	if (a >= b)
	{
		if (a >= c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b >= c)
			return (b);
		else
			return (c);
	}
}

int	ft_min2(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_min3(int a, int b, int c)
{
	if (a <= b)
	{
		if (a <= c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b <= c)
			return (b);
		else
			return (c);
	}
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
