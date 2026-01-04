/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:18:17 by ayua              #+#    #+#             */
/*   Updated: 2026/01/04 16:38:52 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 0)
	{
		move_n_target(stack_a, stack_b);
		calc_pos(stack_a);
		calc_cost(stack_a);
	}
}
