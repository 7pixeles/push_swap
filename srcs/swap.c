/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:50:12 by ayua              #+#    #+#             */
/*   Updated: 2026/01/03 19:43:30 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_move(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL || stack->size <= 2 || stack->top == NULL)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->bottom == second)
		stack->bottom = first;
}

void	swap_sa(t_stack *stack_a)
{
	swap_move(stack_a);
	write(1, "sa\n", 3);
}

void	swap_sb(t_stack *stack_b)
{
	swap_move(stack_b);
	write(1, "sb\n", 3);
}

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_move(stack_a);
	swap_move(stack_b);
	write(1, "ss\n", 3);
}
