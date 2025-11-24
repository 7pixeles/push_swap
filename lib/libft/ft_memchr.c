/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:10:48 by ayucarre          #+#    #+#             */
/*   Updated: 2025/10/16 11:48:07 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cast_s;
	unsigned char	cast_c;
	size_t			i;

	cast_s = (unsigned char *)s;
	cast_c = c;
	i = 0;
	while (i < n)
	{
		if (cast_s[i] == cast_c)
			return (&cast_s[i]);
		i++;
	}
	return (NULL);
}
