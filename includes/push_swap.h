/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:49 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/07 17:39:04 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/* push_swap magic numbers */
#define PS_OK		0
#define PS_ERROR	1
#define MAX_INT		"2147483647"
#define MIN_INT		"-2147483648"

/* typedef */
typedef int	t_ps_error;

/* push swap */
int			main(int argc, char **argv);

/* stack utils */
void		init_stack(t_list **stack_a, t_list **stack_b);
void		free_stack(t_list **stack);
void		print_stack(t_list **stack);

/* split argv2list */
void		s_array_free(char **s_array, int count);
t_ps_error	split_argv2list(int argc, char **argv, t_list **stack_a);

/* input control */
t_ps_error	is_bigger_than_int(char *str, int len);
t_ps_error	is_duplicated(char *str1, char *str2);
t_ps_error	is_format_incorrect(char *str);
t_ps_error	input_control(t_list **stack_a);

/* parse input */
t_ps_error	parse_input(t_list **lst);

