/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-02 15:32:27 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-02 15:32:27 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	first = *stack;// Guardamos el primer nodo // A
	last = ft_lstlast(*stack);// Encontramos el último nodo // D
	*stack = first->next;// Movemos la cabeza al segundo nodo // B
	last->next = first;// Conectamos el antiguo primer nodo al final D -> A
	first->next = NULL;// Cortamos su siguiente para terminar la lista A > NULL
	return (1);
}

void	rotate_ra(t_list **stack_a)
{
	if (rotate(stack_a))
		write(1, "ra\n", 3);
}

void	rotate_rb(t_list **stack_b)
{
	if (rotate(stack_b))
		write(1, "rb\n", 3);
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	if (rotate(stack_a) && rotate(stack_b))
		write(1, "rr\n", 3);
}
