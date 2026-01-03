/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:24:12 by ayucarre          #+#    #+#             */
/*   Updated: 2026/01/03 13:49:01 by ayua             ###   ########.fr       */
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
	calc_index(&stack_a);
	if (stack_is_sorted(&stack_a))
		exit_code(&stack_a, NULL, ALREADY_SORTED);
	init_stack(&stack_b, 'B');
	if ((&stack_a)->size == 2)
		swap_sa(&stack_a);
	else if ((&stack_a)->size == 3)
		sort_three(&stack_a);
	else if ((&stack_a)->size == 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
	ft_printf("\nAFTER:\n-------\n");
	pretty_stack(&stack_a, &stack_b);
	exit_code(&stack_a, &stack_b, ALREADY_SORTED);
}
