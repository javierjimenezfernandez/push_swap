/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:47 by javjimen          #+#    #+#             */
/*   Updated: 2024/03/12 15:49:22 by javjimen         ###   ########.fr       */
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
		print_stacks(stack_a, stack_b);
		stack_size = ft_lstsize(*stack_a);
		ft_printf("Stack size: %d\n\n", stack_size);
		ft_printf("sa\n");
		sa(stack_a, stack_o);
		print_stacks(stack_a, stack_b);
		ft_printf("\n");
		ft_printf("pb\n");
		pb(stack_b, stack_a, stack_o);
		print_stacks(stack_a, stack_b);
		ft_printf("\n");
		ft_printf("pb\n");
		pb(stack_b, stack_a, stack_o);
		print_stacks(stack_a, stack_b);
		ft_printf("\n");
		ft_printf("rr\n");
		rr(stack_a, stack_b, stack_o);
		print_stacks(stack_a, stack_b);
		ft_printf("\n");
		ft_printf("rra\n");
		rra(stack_a, stack_o);
		print_stacks(stack_a, stack_b);
		ft_printf("\n");
		ft_printf("Operations: \n");
		print_operations(stack_o);
		// ordering algorithm
		free_stacks(stack_a, stack_b, stack_o);
	}
	return (PS_OK);
}
