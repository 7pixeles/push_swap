/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:59:16 by ayua              #+#    #+#             */
/*   Updated: 2025/12/22 20:27:11 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->bottom->value;
	
	if (first < second && second > third && third > first) // A C B --> C A B --> A B C		(OK)
	{
		r_rotate_rra(stack);
		swap(stack);
	}
	if (first > second && second < third && third > first) // B A C --> A B C		(OK)
		swap(stack);
	if (first > third && second > third && second > first) // B C A --> A B C		(OK) 
		r_rotate_rra(stack);
	if (first > second && second < third && third < first) // C A B --> A B C		(OK)
		rotate_ra(stack);
	if	(first > second && second > third && third < first) // C B A --> B C A --> A B C		(X)
	{
		swap(stack);
		r_rotate_rra(stack);
	}
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
}
/*
* CASES:
	A B C 										(OK)	1 2 3
	A C B -> B A C -> A B C		(rra, sa)		(OK)	1 3 2
	B A C -> A B C				(sa)			(OK)	2 1 3
	B C A -> A B C				(rra)			(OK) 	2 3 1
	C A B -> A B C				(ra)			(OK)	3 1 2
	C B A -> B C A -> A B C		(sa, rra)		(X)		3 2 1
*/
