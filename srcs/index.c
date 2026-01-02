/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:35:59 by ayua              #+#    #+#             */
/*   Updated: 2026/01/02 18:01:18 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	swap(int *array, int i, int k)
{
	int	swap;

	swap = array[i];
	array[i] = array[k];
	array[k] = swap;
}

static void	sort_array(int *array, int size)
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

void	index_node(t_stack *stack)
{
	t_node	*tmp_node;
	int		i;
	int		*tmp_array;

	tmp_node = stack->top;
	i = 0;
	if (stack->size < 2)
		return ;
	tmp_array = copy_stack_to_array(stack);
	sort_array(tmp_array, stack->size);
	while (tmp_node)
	{
		i = 0;
		while (i < stack->size)
		{
			if (tmp_array[i] == tmp_node->value)
			{
				tmp_node->index = i;
				break ;
			}
			i++;
		}
		tmp_node = tmp_node->next;
	}
	free (tmp_array);
}

void	calc_position(t_stack *stack)
{
	t_node	*tmp_node;
	int		i;
	tmp_node = stack->top;
	i = 0;
	while (tmp_node && i < stack->size)
	{
		tmp_node->pos = i;
		i++;
		tmp_node = tmp_node->next;
	}
}
