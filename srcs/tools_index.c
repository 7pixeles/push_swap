/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:35:59 by ayua              #+#    #+#             */
/*   Updated: 2026/01/08 18:08:01 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *array, int i, int k)
{
	int	swap;

	swap = array[i];
	array[i] = array[k];
	array[k] = swap;
}

int	*copy_stack_to_array(t_stack *stack)
{
	t_node	*tmp;
	int		*array_tmp;
	int		size;
	int		i;

	size = stack->size;
	i = 0;
	array_tmp = ft_calloc(size, sizeof(int));
	tmp = stack->top;
	while (tmp && i < size)
	{
		array_tmp[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (array_tmp);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	k;
	int	sorted;

	i = 0;
	while (i < size - 1)
	{
		sorted = 1;
		k = 0;
		while (k < (size - i - 1))
		{
			if (array[k] > array[k + 1])
			{
				swap(array, k, k + 1);
				sorted = 0;
			}
			k++;
		}
		if (sorted == 1)
			break ;
		i++;
	}
}
