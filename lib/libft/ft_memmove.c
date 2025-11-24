/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:02:51 by ayucarre          #+#    #+#             */
/*   Updated: 2025/10/16 11:48:45 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rev_cpy(unsigned char *dst, const char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		dst[n] = src[n];
	}
}

static void	fw_cpy(unsigned char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		dst[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_cst;
	const char			*src_tmp;

	dst_cst = (unsigned char *)dst;
	src_tmp = (const char *)src;
	if (!src && !dst)
		return (NULL);
	if (src == dst)
		return (dst);
	if (src < dst)
		rev_cpy(dst_cst, src_tmp, n);
	else
		fw_cpy(dst_cst, src_tmp, n);
	return (dst);
}
