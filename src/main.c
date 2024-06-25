/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:47 by javjimen          #+#    #+#             */
/*   Updated: 2024/06/25 19:46:52 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	**stack_o;
	int		stack_size;

	if (argc > 1)
	{
		stack_a = (t_list **)malloc(sizeof(t_list *));
		stack_b = (t_list **)malloc(sizeof(t_list *));
		stack_o = (t_list **)malloc(sizeof(t_list *));
		if (split_argv2list(argc, argv, stack_a) || input_control(stack_a) || \
			parse_input(stack_a))
		{
			ft_putstr_fd("Error\n", 2);
			return (PS_ERROR);
		}
		/* debug */
		ft_printf("Original stacks:\n");
		print_stacks(stack_a, stack_b);

		stack_size = ft_lstsize(*stack_a);

		/* debug */
		ft_printf("size: %d\n", stack_size);
		ft_printf("---------------------------------------------\n\n");

		compute_operations(stack_a, stack_b, stack_o, stack_size);

		/* debug */
		ft_printf("---------------------------------------------\n\n");
		ft_printf("Result: \n");
		print_stacks(stack_a, stack_b);
		ft_printf("\n");
		ft_printf("%d operations: \n", ft_lstsize(*stack_o));

		print_operations(stack_o);
		free_stacks(stack_a, stack_b, stack_o);
	}
	return (PS_OK);
}
