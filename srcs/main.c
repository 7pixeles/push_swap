/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:24:12 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/17 18:43:00 by ayua             ###   ########.fr       */
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
	init_stack(&stack_b, 'B');
	// HACE COSAS
	pretty_stack(&stack_a, &stack_b);
	// HASTA AQUI
	exit_code(&stack_a, &stack_b, ALREADY_SORTED);
	return (0);
}
