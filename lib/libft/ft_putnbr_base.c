/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:42:13 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/07 18:46:58 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned int n, char *base)
{
	int	count;
	int	c;

	c = 0;
	count = 0;
	if (n >= 16)
		count += ft_putnbr_base(n / 16, base);
	c = n % 16;
	count += ft_putchar(base[c]);
	return (count);
}
