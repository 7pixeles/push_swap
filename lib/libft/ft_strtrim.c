/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:00:12 by ayucarre          #+#    #+#             */
/*   Updated: 2025/10/16 13:03:54 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	end;
	size_t	start;
	char	*new_s;

	if (!s1 || !set)
		return (NULL);
	set_len = ft_strlen(set);
	end = ft_strlen(s1);
	start = 0;
	while (s1 && ft_memchr(set, s1[start], set_len))
		start++;
	while (s1 && ft_memchr(set, s1[end - 1], set_len) && start < end)
		end--;
	if (start >= end)
	{
		start = 0;
		end = 0;
	}
	new_s = ft_substr(s1, start, (end - start));
	return (new_s);
}
