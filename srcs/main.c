/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-04 14:24:12 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-04 14:24:12 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO EN código final, sustituir errores por code exit
int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (!parser(argv, &stack_a))
	{
		ft_lstclear(&stack_a, del);
		write(2, "Error\n", 6);
		exit(1);
	}
	pretty_stack(stack_a, stack_b);

	// TODO Sustituir por code exit
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	return (0);
}
