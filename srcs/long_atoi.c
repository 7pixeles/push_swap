/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-02 09:39:46 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-02 09:39:46 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	sign_nbr(char *nptr, long int *i)
{
	long int	sign;

	sign = 1;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			sign = -1;
		if (!ft_isdigit(nptr[*i + 1]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		(*i)++;
	}
	return (sign);
}

long int	ft_long_atoi(char *nptr)
{
	long int	i;
	long int	n;
	long int	sign;

	i = 0;
	n = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = sign_nbr(nptr, &i);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		n = 10 * n + (nptr[i] - '0');
		if ((n * sign) < INT_MIN || (n * sign) > INT_MAX)
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
	return (n * sign);
}
