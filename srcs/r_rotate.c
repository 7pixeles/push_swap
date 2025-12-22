/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:03:52 by ayua              #+#    #+#             */
/*   Updated: 2025/12/22 18:35:15 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate_move(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = pop_bottom(stack);
	push_top(stack, node);
}

void	r_rotate_rra(t_stack *stack_a)
{
	r_rotate_move(stack_a);
	write(1, "rra\n", 4);
}

void	r_rotate_rrb(t_stack *stack_b)
{
	r_rotate_move(stack_b);
	write(1, "rrb\n", 4);
}

void	r_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate_move(stack_a);
	r_rotate_move(stack_b);
	write(1, "rrr\n", 4);
}
