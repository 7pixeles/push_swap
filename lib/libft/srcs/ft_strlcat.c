/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:12:22 by ayucarre          #+#    #+#             */
/*   Updated: 2025/10/16 11:49:39 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	total_len;

	j = 0;
	i = 0;
	while (dst[i] && i < size)
		i++;
	total_len = ft_strlen(src) + i;
	if (ft_strlen(dst) >= size)
		return (total_len);
	while (src[j] && i < (size - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (total_len);
}
