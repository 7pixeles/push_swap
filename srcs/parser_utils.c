/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:40:37 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/26 20:39:08 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * ✔️ Corregida
int	ft_atol_ps(const char *nptr, int *num)
{
	int		i;
	long	n;
	long	sign;

	sign = 1;
	i = 0;
	n = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = 10 * n + (nptr[i] - '0');
		if ((n * sign) < INT_MIN || (n * sign) > INT_MAX)
			return (0);
		i++;
	}
	*num = (int)(n * sign);
	return (1);
}

// * ✔️ Corregida
int	is_valid_num(char *nptr)
{
	int	i;

	if (!nptr || nptr[0] == '\0')
		return (0);
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	if (!ft_isdigit(nptr[i]))
		return (0);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (0);
		i++;
	}
	return (1);
}

// * ✔️ Corregida
int	has_duplicate(t_stack *stack, int nbr)
{
	t_node	*current;

	if (!stack || stack->top == NULL)
		return (0);
	current = stack->top;
	while (current != NULL)
	{
		if (current->value == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}
