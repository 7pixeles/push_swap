/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:00:42 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/26 19:07:49 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_mem(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static size_t	count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	word;

	i = 0;
	count = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			count++;
			word = 1;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	**get_words(char **array, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = count_word(s, c);
	while (s[j] != '\0' && i < count)
	{
		while (s[j] == c)
		{
			j++;
		}
		array[i] = ft_substr(s, j, word_len(&s[j], c));
		if (!array[i])
		{
			free_mem(array);
			return (NULL);
		}
		j = j + word_len(&s[j], c);
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (get_words(array, s, c));
}
