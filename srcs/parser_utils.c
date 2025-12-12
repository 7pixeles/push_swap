/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-02 09:40:37 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-02 09:40:37 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char	*nptr, int *error)
{
	int	i;
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
			exit(1);
		i++;
	}
	return (n * sign);
}

int	is_valid_num(char *nptr)
{
	int i;

	i = 0;
	while (nptr[i])
	{
		if (nptr[i] == '+' || nptr[i] == '-')
		{
			if (!ft_isdigit(nptr[i + 1]))
				return (0);
		}
		else if (!ft_isdigit(nptr[i]))
			return (0);
		i++;
	}
	return (1);
}

// TODO Modificar para encajar con la nueva estructura de nodos
int is_duplicate_num(t_list **stack_a, long nbr)
{
	t_list	*aux_stack;
	t_list	*t_list_new;
	aux_stack = *stack_a;
	int		*value;

	value = malloc(sizeof(int));
	if (!value)
		return (0);
	*value = (int)nbr;
	t_list_new = ft_lstnew(value);
	while (aux_stack != NULL)
	{
		if (*(int *)aux_stack->content == *(int *)t_list_new->content)
		{
			free(value);
			free(t_list_new);
			return (0);
		}
		aux_stack = aux_stack->next;
	}
	// TODO En código final este iría fuera:
	return (ft_lstadd_back(stack_a, t_list_new), 1);
}
