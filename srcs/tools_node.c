/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:33:10 by ayua              #+#    #+#             */
/*   Updated: 2026/01/04 15:32:16 by ayua             ###   ########.fr       */
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
	new_node->cost = 0;
	new_node->pos = 0;
	new_node->dir = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	calc_index(t_stack *stack)
{
	t_node	*current;
	int		i;
	int		*tmp_array;

	current = stack->top;
	i = 0;
	if (stack->size < 2)
		return ;
	tmp_array = copy_stack_to_array(stack);
	sort_array(tmp_array, stack->size);
	while (current)
	{
		i = 0;
		while (i < stack->size)
		{
			if (tmp_array[i] == current->value)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free (tmp_array);
}

void	calc_pos(t_stack *stack)
{
	t_node	*current;
	int		pos;

	if (!stack)
		return ;
	pos = 0;
	current = stack->top;
	while (current)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

void	calc_cost(t_stack *stack)
{
	t_node	*current;
	int	size;

	if (!stack)
		return;
	size = calc_size(stack);
	calc_pos(stack);
	current = stack->top;
	while (current)
	{	
		if (current->pos <= size / 2)
		{
			current->cost = current->pos;
			current->dir = 1;
		}
		else
		{
			current->cost = size - current->pos;
			current->dir = -1;
		}
		current = current->next;
	}
	stack->size = size;
}

int	find_low_cost(t_stack *stack)
{
	int	i;
	int	low_cost;
	
	i = 0;
	low_cost = 0;
	while (i < stack->size)
	{
		if (stack->top->cost < low_cost)
			low_cost = i;
		i++;
	}
	return (low_cost);
}
