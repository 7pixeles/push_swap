/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:01:04 by ayucarre          #+#    #+#             */
/*   Updated: 2025/10/16 12:44:06 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int num)
{
	size_t	size;

	size = 1;
	if (num < 0)
		size++;
	while (num / 10 != 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	size;
	long	cast_n;

	cast_n = (long)n;
	size = ft_intlen(cast_n);
	if (n == 0)
		return (ft_strdup("0"));
	res = ft_calloc(size + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (cast_n < 0)
	{
		res[0] = '-';
		cast_n = cast_n * -1;
	}
	while (cast_n > 0)
	{
		res[size - 1] = (cast_n % 10) + '0';
		cast_n = cast_n / 10;
		size--;
	}
	return (res);
}
