/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:55:25 by ayua              #+#    #+#             */
/*   Updated: 2026/01/03 13:38:06 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		dir_cost(t_stack *stack, int cost)
{
	t_node	*current;
	int		pos;
	int		half_top;

	half_top = (stack->size) / 2;
	pos = 0;
	if (stack->top == NULL)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->cost == cost)
			break ;
		pos++;
		current = current->next;
	}
	if (current == NULL)
		return (0);
	if (pos > half_top)
		return (0);
	else
		return (1);
}

int		set_cost_min(t_stack *stack)
{
	int		cost_min;
	t_node	*current;
	
	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	cost_min = current->cost;
	while (current)
	{
		if (current->cost < cost_min)
			cost_min = current->cost;
		current = current->next;
	}
	return (cost_min);
}

void	min_moves(t_stack *stack_from, t_stack *stack_to, int cost)
{
	if (dir_cost(stack_to, cost))
	{
		while (stack_to->top->cost != cost)
		{
			rotate_ra(stack_to);
		}
	}
	else
	{
		while ((stack_to->top != NULL) && (stack_to->top->cost != cost))
		{
			r_rotate_rra(stack_to);
		}
	}
	push(stack_to, stack_from);
}
