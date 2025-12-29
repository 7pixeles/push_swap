/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:59:16 by ayua              #+#    #+#             */
/*   Updated: 2025/12/29 14:45:00 by ayua             ###   ########.fr       */
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

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int min_index;

	min_index = set_index_min(stack_a);
	min_moves(stack_a, stack_b, min_index);
	min_moves(stack_a, stack_b, min_index);
	if (!stack_is_sorted(stack_a))
		sort_three(stack_a);
	if (stack_is_sorted(stack_b))
		swap_sb(stack_b);
	while (stack_b->top != NULL)
	{
		push(stack_b, stack_a);
	}
}
