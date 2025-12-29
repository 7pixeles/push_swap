/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:10:56 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/27 17:56:20 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

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

int	stack_is_sorted(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->top;
	if (stack_a->top == NULL || stack_a->top == stack_a->bottom)
		return (1);
	while (current->next != NULL)
	{
		if (current->index < current->next->index)
			current = current->next;
		else
			return (0);
	}
	return (1);
}
