/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:38:22 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/19 20:16:53 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*top_a;

	top_a = pop_top(stack_from);
	push_top(stack_to, top_a);
	return (1);
}

void	push_pa(t_stack *stack_from, t_stack *stack_to)
{
	if (push(stack_from, stack_to))
		write(1, "pa\n", 3);
}

void	push_pb(t_stack *stack_from, t_stack *stack_to)
{
	if (push(stack_from, stack_to))
		write(1, "pb\n", 3);
}
