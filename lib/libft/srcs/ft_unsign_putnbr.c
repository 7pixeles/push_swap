/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:27:56 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/07 18:43:04 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsign_putnbr(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	c = 0;
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	if (n < 10)
	{
		c = n + '0';
		count += ft_putchar(c);
	}
	return (count);
}
