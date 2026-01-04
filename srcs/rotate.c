/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:03:52 by ayua              #+#    #+#             */
/*   Updated: 2026/01/04 23:22:45 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_move(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = pop_top(stack);
	push_bottom(stack, node);
}

void	rotate_ra(t_stack *stack_a)
{
	rotate_move(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_rb(t_stack *stack_b)
{
	rotate_move(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_move(stack_a);
	rotate_move(stack_b);
	write(1, "rr\n", 3);
}
