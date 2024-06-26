/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv2list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:54:24 by javjimen          #+#    #+#             */
/*   Updated: 2024/06/26 21:27:25 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_array_free(char **s_array, int count)
{
	while (count >= 0)
	{
		free(s_array[count]);
		count--;
	}
	free(s_array);
}

t_ps_error	split_argv2list(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		j;
	char	**splitted_argv;
	t_list	*new_node;

	i = 1;
	while (i < argc)
	{
		splitted_argv = ft_split(argv[i], ' ');
		if (!splitted_argv)
			return (PS_ERROR);
		j = 0;
		while (splitted_argv[j] != NULL)
		{
			new_node = ft_lstnew(ft_strdup(splitted_argv[j]));
			if (!new_node)
				return (PS_ERROR);
			ft_printf("in split_argv2list: hi\n");
			ft_lstadd_back(stack_a, new_node);
			ft_printf("in split_argv2list: succesfully added new_node for \"%s\" to the list\n", new_node->content);
			j++;
		}
		s_array_free(splitted_argv, j);
		i++;
	}
	return (PS_OK);
}
