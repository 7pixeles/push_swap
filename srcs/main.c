/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:24:12 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/13 14:21:23 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit_code(NULL, NULL, ERROR_ARGS);
	if (!parser(argv, &stack_a))
		exit_code(stack_a, stack_b, ERROR_PARSING);
	init_stack(stack_a, 'A');
	init_stack(stack_b, 'B');
	pretty_stack(stack_a, stack_b);
	exit_code(stack_a, stack_b, ALREADY_SORTED);
	return (0);
}
