/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:49 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/29 12:36:44 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/* push_swap magic numbers */
#define	PS_OK		0
#define PS_ERROR	1

/* typedef */
typedef	int	ps_error_t;

/* push swap */
int	main(int argc, char **argv);

/* input control */
ps_error_t	is_bigger_than_int(char *str, int len);
ps_error_t	is_duplicated(char *str1, char *str2);
ps_error_t	input_control(int argc, char **argv);

/* parse input */
