/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:47 by javjimen          #+#    #+#             */
/*   Updated: 2024/10/13 13:18:38 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*stack_o;

	if (argc > 1)
	{
		stack_a = (t_list *)malloc(sizeof(t_list));
		stack_b = (t_list *)malloc(sizeof(t_list));
		stack_o = (t_list *)malloc(sizeof(t_list));
		if (stacks_init(&stack_a, &stack_b, &stack_o) == PS_MALLOC_FAIL)
			return (PS_MALLOC_FAIL);
		if ((argc == 2 && argv[1][0] == '\0') ||
			split_argv2list(argv, &stack_a) || input_control(&stack_a))
		{
			free_stacks(&stack_a, &stack_b, &stack_o, free);
			ft_putstr_fd("Error\n", 2);
			return (PS_ERROR);
		}
		if (compute_operations(&stack_a, &stack_b, &stack_o, \
			ft_lstsize(stack_a)) == PS_MALLOC_FAIL)
			return (PS_MALLOC_FAIL);
		print_operations(&stack_o);
		free_stacks(&stack_a, &stack_b, &stack_o, free);
	}
	return (PS_OK);
}
