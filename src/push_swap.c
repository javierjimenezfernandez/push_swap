/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:27:47 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/29 17:23:11 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*dummy_node;
	//t_list	*i;

	dummy_node = NULL;
	stack_a = &dummy_node;
	stack_b = &dummy_node;
	if (argc > 1)
	{
		if (input_control(argc, argv, stack_a))
			ft_putstr_fd("Error\n", 2);
		//parse_input(stack_a);
		/*i = *stack_a;
		while (i)
		{
			ft_printf("%s\n", i->content);
			i = i->next;
		}*/
	}
	return (0);
}
