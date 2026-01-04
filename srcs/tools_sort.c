/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:55:25 by ayua              #+#    #+#             */
/*   Updated: 2026/01/04 23:30:20 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_stack *stack)
{
	t_node *current;
	int min_value;
	int	min_pos;
	int	pos;
	
	current = stack->top;
	min_value = current->value;
	pos = 0;
	min_pos = 0;
	while (current->next)
	{
		pos++;
		current = current->next;
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = pos;
		}
	}
	return (min_pos);
}

int get_max_index_pos(t_stack *stack)
{
	t_node *current;
	int max_index;
	int	max_pos;
	int	pos;
	
	current = stack->top;
	max_index = current->index;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

void push_max_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	dist;
	int	max_pos;
	
	while(stack_b->size > 0)
	{
		max_pos = get_max_index_pos(stack_b);
		if (max_pos <= stack_b->size / 2)
		{
			while (max_pos > 0)
			{
				rotate_rb(stack_b);
				max_pos--;
			}
		}
		else
		{
			dist = stack_b->size - max_pos;
			while (dist > 0)
			{
				r_rotate_rrb(stack_b);
				dist--;
			}
		}
		push(stack_b, stack_a);
	}
}

void push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	dist;
	int	min_pos;
	
	while(stack_b->size > 0)
	{
		min_pos = get_min_pos(stack_b);
		if (min_pos <= stack_a->size / 2)
		{
			while (min_pos > 0)
			{
				rotate_ra(stack_a);
				min_pos--;
			}
		}
		else
		{
			dist = stack_b->size - min_pos;
			while (dist > 0)
			{
				r_rotate_rra(stack_a);
				dist--;
			}
		}
		push(stack_a, stack_b);
	}
}

void push_rotate_b(t_stack *stack_a, t_stack *stack_b, int *range)
{
	push(stack_a, stack_b);
	rotate_rb(stack_b);
	range++;
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	range;

	if (!calc_index(stack_a))
		exit_code(stack_a, stack_b, EXIT_FAILURE);
	if (stack_a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 40;
	range = 0;
	while (stack_a->size > 0)
	{
		if (stack_a->top->index <= range)
			push_rotate_b(stack_a, stack_b, &range);
		else if(stack_a->top->index <= range + chunk_size)
		{
			push(stack_a, stack_b);
			range++;
		}
		else
			rotate_ra(stack_a);
	}
	push_max_to_a(stack_a, stack_b);
}
