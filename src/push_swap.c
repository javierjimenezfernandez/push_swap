/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:47 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/11 21:31:42 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc > 1)
	{
		stack_a = (t_list **)malloc(sizeof(t_list *));
		stack_b = (t_list **)malloc(sizeof(t_list *));
		//init_stack(stack_a, stack_b);
		if (split_argv2list(argc, argv, stack_a) || input_control(stack_a) || \
			parse_input(stack_a))
		{
			ft_putstr_fd("Error\n", 2);
			return (PS_ERROR);
		}
		print_stack(stack_a);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (PS_OK);
}
