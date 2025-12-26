/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:38:22 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/26 20:38:48 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_move(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*top_a;

	top_a = pop_top(stack_from);
	push_top(stack_to, top_a);
}
void	push(t_stack *stack_from, t_stack *stack_to)
{
	push_move(stack_from, stack_to);
	if (stack_from->name == 'A')
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}
