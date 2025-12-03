/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-02 15:18:41 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-02 15:18:41 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*tmp;
	
	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap_sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
