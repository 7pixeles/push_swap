/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:35:59 by ayua              #+#    #+#             */
/*   Updated: 2025/12/26 20:37:39 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_stack_to_array(t_stack *stack)
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
	int		size;

	tmp_node = stack->top;
	i = 0;
	size = stack->size;
	if (size < 2)
		return ;
	//hace una copia del stack a un array -> [DONE]
	tmp_array = copy_stack_to_array(stack);
	//ordena el array -> [DONE]
	sort_array(tmp_array, size);
	//asigna el index del array al nodo del stack 
	while (tmp_node)
	{
		i = 0;
		while (i < size)
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
	//libera el array_tmp
	free (tmp_array);
	//no devuelve nada
}
