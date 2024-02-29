/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:51:00 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/29 14:17:20 by javjimen         ###   ########.fr       */
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

ps_error_t	split_argv(int argc, char **argv, t_list **stack_a)
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
			ft_lstadd_back(stack_a, new_node);
			j++;
		}
		s_array_free(splitted_argv, j);
		i++;
	}
	return (PS_OK);
}

/*ps_error_t	parse_input(t_list **stack_a)
{
	return (PS_OK);
}*/
