/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:50:12 by ayua              #+#    #+#             */
/*   Updated: 2025/12/22 18:16:27 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_move(t_stack *stack)
{
	t_node *first;
	t_node *second;

	first = stack->top;
	second = first->next;
	first->next = second->next;
	if(second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
	if (stack->bottom == second)
		stack->bottom = first;
}

void	swap(t_stack *stack)
{
	swap_move(stack);
	if (stack->name == 'A')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

