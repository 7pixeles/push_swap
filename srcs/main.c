/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:24:12 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/19 20:17:16 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		exit_code(NULL, NULL, 0);
	if (!parser(argc, argv, &stack_a))
		exit_code(&stack_a, NULL, ERROR_PARSING);

/* 	if (stack_is_sorted(stack_a))
		exit_code(&stack_a, NULL, ALREADY_SORTED); */
	init_stack(&stack_b, 'B');


	/* if ((&stack_a)->size == 2)
		sa(&stack_a);
	else if ((&stack_a)->size <= 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b); */

	pretty_stack(&stack_a, &stack_b);
	exit_code(&stack_a, &stack_b, ALREADY_SORTED);
	return (0);
}
