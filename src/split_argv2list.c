/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv2list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:54:24 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/12 12:50:41 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_array_free(char **s_array)
{
	char	**s_array_cpy;

	s_array_cpy = s_array;
	while (*s_array_cpy)
	{
		free(*s_array_cpy);
		s_array_cpy++;
	}
	free(*s_array_cpy);
	free(s_array);
}

t_ps_error	add_node(char ***splitted_argv, int i, t_list **new_node, \
						t_list **stack)
{
	*new_node = ft_lstnew(ft_strdup(*(splitted_argv[i])));
	if (!(*new_node))
	{
		s_array_free(*splitted_argv);
		return (PS_MALLOC_FAIL);
	}
	ft_lstadd_back(stack, *new_node);
	return (PS_OK);
}

t_ps_error	split_argv2list(char **argv, t_list **stack_a)
{
	int		i;
	char	**splitted_argv;
	t_list	*new_node;

	argv++;
	while (*argv)
	{
		splitted_argv = ft_split(*argv, ' ');
		if (!splitted_argv)
			return (PS_MALLOC_FAIL);
		i = 0;
		while (splitted_argv[i] != NULL)
		{
			if (add_node(&splitted_argv, i, &new_node, stack_a) \
							== PS_MALLOC_FAIL)
				return (PS_MALLOC_FAIL);
			i++;
		}
		s_array_free(splitted_argv);
		argv++;
	}
	return (PS_OK);
}
