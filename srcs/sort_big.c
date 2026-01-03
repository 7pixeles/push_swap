/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:18:17 by ayua              #+#    #+#             */
/*   Updated: 2026/01/03 14:18:40 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	cost_min;
	cost_min = 0;
	while (stack_a->bottom != NULL)
	{
		while (stack_a->top != NULL)
		{
			min_moves(stack_a, stack_b, cost_min);
			calc_cost(stack_a);
			cost_min = set_cost_min(stack_a);
		}
	} 
	/* while (stack_b->top != NULL)
	{
		push(stack_b, stack_a);
	} */
}
