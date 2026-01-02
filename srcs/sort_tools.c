/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:55:25 by ayua              #+#    #+#             */
/*   Updated: 2026/01/02 18:02:10 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_index_max(t_stack *stack)
{
	int		index_max;
	t_node	*current;
		
	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	index_max = current->index;
	while (current)
	{
		if (current->index > index_max)
			index_max = current->index;
		current = current->next;
	}
	return (index_max);
}

int		set_index_min(t_stack *stack)
{
	int		index_min;
	t_node	*current;
	
	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	index_min = current->index;
	while (current)
	{
		if (current->index < index_min)
			index_min = current->index;
		current = current->next;
	}
	return (index_min);
}

void	min_moves(t_stack *stack_to, t_stack *stack_from, int index)
{
	if (is_index_in_top(stack_to, index))
	{
		while (stack_to->top->index != index)
		{
			rotate_ra(stack_to);
		}
	}
	else
	{
		while (stack_to->top->index != index)
		{
			r_rotate_rra(stack_to);
		}
	}
	push(stack_to, stack_from);
}

int		is_index_in_top(t_stack *stack, int index)
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
		if (current->index == index)
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

void	calc_cost_dir(t_stack *stack, t_node *node)
{
	if (node->pos <= stack->size / 2)
	{
		node->cost = node->pos;
		node->dir = 1;
	}
	else
	{
		node->cost = stack->size - node->pos;
		node->dir = -1;
	}
}
