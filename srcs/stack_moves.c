/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:45:44 by ayua              #+#    #+#             */
/*   Updated: 2025/12/19 19:38:27 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->prev = NULL;
	node->next = stack->top;
	if (stack->top != NULL)
		stack->top->prev = node;
	stack->top = node;
	if (stack->bottom == NULL)
		stack->bottom = node;
	stack->size++;
}

void	push_bottom(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->next = NULL;
	node->prev = stack->bottom;
	if (stack->bottom != NULL)
		stack->bottom->next = node;
	stack->bottom = node;
	if (stack->top == NULL)
		stack->top = node;
	stack->size++;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->top == NULL)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	if (stack->top != NULL)
		stack->top->prev = NULL;
	else
		stack->bottom = NULL;
	node->prev = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->bottom == NULL)
		return (NULL);
	node = stack->bottom;
	stack->bottom = node->prev;
	if (stack->bottom != NULL)
		stack->bottom->next = NULL;
	else
		stack->top = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}
