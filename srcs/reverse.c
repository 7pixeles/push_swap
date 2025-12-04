/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-02 15:42:05 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-02 15:42:05 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize(*stack); // Size = 4
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	first = ft_lstlast(*stack); // Encontramos el último nodo // D
	last = *stack; // COPIA DE STACK ABCD
	while (i < (size - 2)) // i = 0, 1 , 2 , 3
	{
		last = last->next; // Iterador
		i++;
	}
	last->next = NULL; // C-> NULL
	first->next = *stack;// Movemos el último nodo al principio // D -> A
	*stack = first; //stack empieza en D
	return (1);
}

void	reverse_rra(t_list **stack_a)
{
	if (reverse(stack_a))
		write(1, "rra\n", 4);
}

void	reverse_rrb(t_list **stack_b)
{
	if (reverse(stack_b))
		write(1, "rrb\n", 4);
}

void	reverse_rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	if (reverse(stack_a) && reverse(stack_b))
		write(1, "rrr\n", 4);
}
