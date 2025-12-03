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

static void	rotate(t_list **stack)
{
	t_list *first;
	t_list *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;				// Guardamos el primer nodo // A
	last = ft_lstlast(*stack); // Encontramos el último nodo // D
	*stack = first->next;		// Movemos la cabeza al segundo nodo // B
	last->next = first;			// Conectamos el antiguo primer nodo al final D -> A
	first->next = NULL;			// Cortamos su siguiente para terminar la lista A > NULL
}

void	rotate_ra(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_rb(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
