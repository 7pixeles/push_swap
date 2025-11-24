/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxf_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:50:34 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/07 18:17:56 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ptr(unsigned long ptr, char *base)
{
	int	count;
	int	c;

	count = 0;
	c = 0;
	if (ptr >= 16)
		count += get_ptr(ptr / 16, base);
	c = ptr % 16;
	count += ft_putchar(base[c]);
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + get_ptr(ptr, HEX_LOW));
}
