/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-11 11:06:29 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-11 11:06:29 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_list **stack)
{
	t_list *aux;
	
	if (!stack || !*stack || !(*stack)->next)
		return ;
		
	aux = *stack;
	while (aux && aux->next)
	{

		aux = aux->next;
	}
}