/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-04 16:35:50 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-04 16:35:50 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nmb(t_list **stack)
{
	while ((*stack)->next != NULL)
	{
		if ((*stack)->content > (*stack)->next)
			swap_sa(stack);
		*stack = (*stack)->next;
	}
	
	
}