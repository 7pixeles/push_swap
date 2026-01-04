/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:55:25 by ayua              #+#    #+#             */
/*   Updated: 2026/01/04 16:41:11 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
/// @brief Busca el primer nodo con el coste más bajo
/// @param stack Puntero al stack en el que buscar el nodo
/// @return Puntero al nodo encontrado
t_node *set_cost_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min_cost;

	if (!stack || !stack->top)
		return NULL;
	calc_pos(stack);
	calc_cost(stack);
	current = stack->top;
	min_cost = current;
	while (current)
	{
		if (current->cost < min_cost->cost)
			min_cost = current;
		current = current->next;
	}
	return min_cost;
}
 */

 /* 
/// @brief Busca el nodo pasado por parámetro en el stack indicado
/// @param stack Puntero al stack en el que buscar el nodo
/// @return Puntero al nodo encontrado, NULL si no lo encuentra
t_node	*find_node_index(t_stack *stack, t_node *node)
{
	t_node	*current;

	if (!stack)
		return NULL;
	current = stack->top;
	while (current)
	{
		if (current->index == node->index)
			return current;
		current = current->next;
	}
	return NULL;
}
 */

/// @brief Mueve n veces los índices más pequeños encontrados en A de manera más eficiente
/// @param stack_from 
/// @param stack_to 
/// @param n 
void	move_n_index(t_stack *stack_from, t_stack *stack_to, int n)
{
	t_node	*low_index;
	int	i;

	i = 0;
	while (i < n)
	{
		low_index = get_index_min(stack_from);
		if (low_index->pos < stack_from->size / 2)
		{
			while (stack_from->top->index != low_index->index)
				rotate_ra(stack_from);
		}
		else
			while (stack_from->top->index != low_index->index)
				r_rotate_rra(stack_from);
		push(stack_from, stack_to);
		i++;
	}
}

void	move_n_target(t_stack *stack_from, t_stack *stack_to)
{
	t_node *target;
	
	if (!stack_from || stack_from->size == 0)
		return ;
	target = find_target(stack_from);
	if (target->pos < stack_from->size / 2)
	{
		while (stack_from->top->index != target->index)
			rotate_ra(stack_from);
	}
	else
		while (stack_from->top->index != target->index)
			r_rotate_rra(stack_from);
	push(stack_from, stack_to);

}

t_node *get_index_min(t_stack *stack)
{
	t_node *current;
	t_node *min_index;

	if (!stack || !stack->top)
		return NULL;
	current = stack->top;
	min_index = current;
	while (current)
	{
		if (current->index < min_index->index)
			min_index = current;
		current = current->next;
	}
	return min_index;
}

t_node *find_target(t_stack *stack)
{
	t_node *current;
	t_node *target;
	int	min_cost;
	int	max_index;

	if (!stack)
		return NULL;
	current = stack->top;
	target = current;
	max_index = current->index;
	min_cost = current->cost;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			min_cost = current->cost;
			target = current;
		}
		else if (current->index == max_index && current->cost < min_cost)
		{
			min_cost = current->cost;
			target = current;
		}
		current = current->next;
	}
	return (target);
}

void	move_target_top(t_stack *stack)
{
	t_node	*target;

	if (!stack || !stack->top)
		return;
	calc_pos(stack);
	calc_cost(stack);
	target = find_target(stack);
	while (stack->top != target)
	{
		if (target->pos <= stack->size / 2 && stack->name == 'A')
			rotate_ra(stack);
		else if(target->pos > stack->size / 2 && stack->name == 'A')
			r_rotate_rra(stack);
		else if (target->pos <= stack->size / 2 && stack->name == 'B')
			rotate_rb(stack);
		else 
			r_rotate_rrb(stack);
	}
}
/* 
t_node	*find_node_cost(t_stack *stack, t_node *node)
{
	t_node	*current;

	if (!stack)
		return NULL;
	current = stack->top;
	while (current)
	{
		if (current->cost == node->cost)
			return current;
		current = current->next;
	}
	return NULL;
} */
