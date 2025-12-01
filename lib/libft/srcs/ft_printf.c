/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:13:55 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/07 18:22:27 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_format(va_list args, char placeholder, size_t f_value)
{
	if (placeholder == 'c')
		f_value += ft_putchar(va_arg(args, int));
	else if (placeholder == 's')
		f_value += ft_putstr(va_arg(args, char *));
	else if (placeholder == 'd' || placeholder == 'i')
		f_value += ft_putnbr(va_arg(args, int));
	else if (placeholder == 'u')
		f_value += ft_unsign_putnbr(va_arg(args, unsigned int));
	else if (placeholder == 'p')
		f_value += ft_putptr(va_arg(args, unsigned long));
	else if (placeholder == 'x')
		f_value += ft_putnbr_base(va_arg(args, unsigned int), HEX_LOW);
	else if (placeholder == 'X')
		f_value += ft_putnbr_base(va_arg(args, unsigned int), HEX_UPP);
	else if (placeholder == '%')
		f_value += ft_putchar('%');
	return (f_value);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count = get_format(args, format[i], count);
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
