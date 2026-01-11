/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:18:17 by ayua              #+#    #+#             */
/*   Updated: 2026/01/11 12:44:33 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	range;

	if (!calc_index(stack_a))
		exit_code(stack_a, stack_b, EXIT_FAILURE);
	if (stack_a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 40;
	range = 0;
	while (stack_a->size > 0)
	{
		if (stack_a->top->index <= range)
			push_rotate_b(stack_a, stack_b, &range);
		else if (stack_a->top->index <= range + chunk_size)
		{
			push(stack_a, stack_b);
			range++;
		}
		else
			rotate_ra(stack_a);
	}
	push_max_to_a(stack_a, stack_b);
}
