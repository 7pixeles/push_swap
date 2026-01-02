/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:12:53 by ayucarre          #+#    #+#             */
/*   Updated: 2026/01/02 18:06:44 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static int	calc_lis(int size, int *tmp_index_array, int *lis)
{
	int	i;
	int	k;
	int	max;
	
	max = 0;
	i = 0;
	while(i < size)
	{
		lis[i] = 1;
		k = 0;
		while (k < i)
		{
			if (tmp_index_array[i] > tmp_index_array[k] && lis[i] < lis[k] + 1)
				lis[i] = lis[k] + 1;
			k++;
		}
		if (lis[i] > max)
			max = lis[i];
		i++;
	}
	return (max);
}

static void	get_nodes_in_lis(t_stack *stack)
{
	t_node *current;
	int	max;
	int i;
	int *tmp_array;
	int *lis;
	
	current = stack->top;
	i = stack->size - 1;
	lis = ft_calloc(stack->size, sizeof(int));
	tmp_array = copy_index_to_stack(stack);
	max = calc_lis(stack->size, tmp_array, lis);
	while (current)
	{
		if(lis[i] == max)
		{
			current->keep = 1;
			max--;
		}
		else
			current->keep = 0;
		current = current->next;
		i--;
	}
	free(lis);
	free(tmp_array);
}

void turk_algo(t_stack *stack_a, t_stack *stack_b)
{
	t_node *current;
	
	current = stack_a->top;
	get_nodes_in_lis(stack_a);
	while(current)
	{
		if (current->keep == 1)
			push(stack_a, stack_b);
		current = current->next;
	}
}
