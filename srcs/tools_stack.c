/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:10:56 by ayucarre          #+#    #+#             */
/*   Updated: 2026/01/03 18:45:36 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, char name)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
}

void	clear_stack(t_stack *stack)
{
	t_node	*tmp_node;
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		tmp_node = current->next;
		free(current);
		current = tmp_node;
	}
	init_stack(stack, stack->name);
}

int	calc_size(t_stack *stack)
{
	t_node *current;
	int size;

	if (!stack)
		return (0);
	size = 0;
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	stack_is_sorted(t_stack *stack_a)
{
	t_node	*current;

	if (!stack_a || !stack_a->top)
		return (1);
	current = stack_a->top;
	if (stack_a->top == NULL || stack_a->top == stack_a->bottom)
		return (1);
	while (current->next)
	{
		if (current->index < current->next->index)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
