/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:07:16 by ayucarre          #+#    #+#             */
/*   Updated: 2026/01/03 11:20:31 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		ft_printf("[%d] %d\n", node->cost, node->value);
		node = node->next;
	}
}

// TODO En código final, eliminar el pretty stack, tiene función prohibida 
void	pretty_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp_a = stack_a->top;
	t_node	*tmp_b = stack_b->top;

	printf("[Stack A] [Stack B]\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a && tmp_b)
		{
			printf("[%d] %d %8d [%-1d]\n", tmp_a->cost, tmp_a->value, tmp_b->value, tmp_b->cost);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		else if (tmp_a)
		{
			printf("[%d] %2d\n", tmp_a->cost, tmp_a->value);
			tmp_a = tmp_a->next;
		}
		else if (tmp_b)
		{
			printf("[%d] %2d\n", tmp_b->cost, tmp_b->value);
			tmp_b = tmp_b->next;
		}
	}
}
