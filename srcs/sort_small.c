/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:59:16 by ayua              #+#    #+#             */
/*   Updated: 2026/01/11 12:09:49 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->index;
	second = stack->top->next->index;
	third = stack->bottom->index;
	if (first < second && second > third && third > first)
	{
		r_rotate_rra(stack);
		swap_sa(stack);
	}
	if (first > second && second < third && third > first)
		swap_sa(stack);
	if (first > third && second > third && second > first)
		r_rotate_rra(stack);
	if (first > second && second < third && third < first)
		rotate_ra(stack);
	if (first > second && second > third && third < first)
	{
		swap_sa(stack);
		r_rotate_rra(stack);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->bottom->index == 2 && stack_a->top->index == 3
		&& stack_a->top->next->index == 0 && stack_a->bottom->prev->index == 1)
		rotate_ra(stack_a);
	else
	{
		push_min_to_b(stack_a, stack_b);
		sort_three(stack_a);
		push(stack_b, stack_a);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->size > 0)
		push(stack_b, stack_a);
}
