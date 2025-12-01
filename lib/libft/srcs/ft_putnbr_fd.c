/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:00:53 by ayucarre          #+#    #+#             */
/*   Updated: 2025/10/16 12:49:42 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	res;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0 && n)
	{
		n = n * (-1);
		write(fd, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	res = (n % 10) + '0';
	write(fd, &res, 1);
}
