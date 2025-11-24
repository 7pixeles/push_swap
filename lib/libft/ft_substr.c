/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:58:25 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/24 17:06:46 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Reserva y devuelve una substring de la string ’s’.
/// La substring empieza desde el índice "start" 
/// y tiene una longitud máxima "len"
/// @param s La string desde la que crear la substring
/// @param start El índice del caracter en "s"
/// desde el que empezar la substring.
/// @param len La longitud máxima de la substring
/// @return La substring resultant. 
/// NULL si falla la reserva de memoria
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		new_s[i] = s[start];
		i++;
		start++;
	}
	new_s[len] = '\0';
	return (new_s);
}
