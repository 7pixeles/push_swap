/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:02:09 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/04 16:52:33 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_tmp;
	const char	*src_tmp;
	size_t		i;

	dest_tmp = (char *)dest;
	src_tmp = (const char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	while (n > i)
	{
		dest_tmp[i] = src_tmp[i];
		i++;
	}
	return (dest);
}
