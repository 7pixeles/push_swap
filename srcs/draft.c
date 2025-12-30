/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 12:42:48 by ayua              #+#    #+#             */
/*   Updated: 2025/12/30 16:51:48 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_n_index_max(t_stack *stack, int n)
{
	int		index_max;
	t_node	*current;
	int		count;
	
	if (!stack || !stack->top)
		return (0);
	count = 1;
	current = stack->top;
	index_max = current->index;
	while (count < n && current)
	{
		if (current->index > index_max)
			index_max = current->index;
		count++;
		current = current->next;
	}
	return (index_max);
}

int	set_n_index_min(t_stack *stack, int n)
{
	int		index_min;
	t_node	*current;
	int		count;
	
	if (!stack || !stack->top)
		return (0);
	count = 1;
	current = stack->top;
	index_min = current->index;
	while (count < n && current)
	{
		if (current->index < index_min)
			index_min = current->index;
		count++;
		current = current->next;
	}
	return (index_min);
}

void	sort_heap_n(t_stack *stack_a, t_stack *stack_b, int size_heap)
{
	int		count;
	int		mount;
	int		index_min;
	
	count = 0;
	if (stack_a->size < size_heap)
		mount = stack_a->size;
	else
		mount = size_heap;
	if ((stack_a->size) < mount)
		mount = stack_a->size;
	while (count < mount && stack_a->top)
	{
		index_min = set_n_index_min(stack_a, mount);
		min_moves(stack_a, stack_b, index_min);
		count++;
	}
}