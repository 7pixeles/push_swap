/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:07:16 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/19 19:38:41 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
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
			printf("%5d%10d\n", tmp_a->value, tmp_b->value);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		else if (tmp_a)
		{
			printf("%5d\n", tmp_a->value);
			tmp_a = tmp_a->next;
		}
		else if (tmp_b)
		{
			printf("%5d\n", tmp_b->value);
			tmp_b = tmp_b->next;
		}
	}
}
