/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-02 15:18:34 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-02 15:18:34 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return (0);
	tmp = *stack_from;// tmp: A -> B -> C
	*stack_from = (*stack_from)->next;// B -> C
	if (*stack_to == NULL)
	{
		tmp->next = NULL;
		*stack_to = tmp; // stack_to: A
	}
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
	return (1);
}

void	push_pa(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_b, stack_a))
		write(1, "pa\n", 3);
}

void	push_pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b))
		write(1, "pb\n", 3);
}
