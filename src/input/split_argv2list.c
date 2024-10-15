/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv2list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:54:24 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/14 16:40:18 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_error	s_array_free(char **s_array)
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
	return (PS_MALLOC_FAIL);
}

t_ps_error	split_argv2list(char **argv, t_list **stack_a)
{
	int		i;
	char	**splitted_argv;
	t_list	*new_node;

	while (*argv)
	{
		splitted_argv = ft_split(*argv, ' ');
		if (!splitted_argv)
			return (PS_MALLOC_FAIL);
		i = 0;
		while (splitted_argv[i] != NULL)
		{
			new_node = ft_lstnew(ft_strdup(splitted_argv[i]));
			if (!new_node)
				return (s_array_free(splitted_argv));
			ft_lstadd_back(stack_a, new_node);
			i++;
		}
		s_array_free(splitted_argv);
		argv++;
	}
	return (PS_OK);
}
