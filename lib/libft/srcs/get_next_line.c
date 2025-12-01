/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:32:33 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/07 18:38:36 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_str(char *stash, char *buffer)
{
	char	*temp_stash;

	temp_stash = ft_strjoin(stash, buffer);
	free(stash);
	stash = temp_stash;
	return (stash);
}

static char	*read_file(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(stash), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || bytes_read == 0)
		{
			if (bytes_read == 0)
				return (free(buffer), stash);
			return (free(buffer), free(stash), NULL);
		}
		buffer[bytes_read] = '\0';
		stash = join_str(stash, buffer);
		if (size_new_line(buffer) != -1)
		{
			free(buffer);
			break ;
		}
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	int		index_n;

	index_n = size_new_line(stash);
	if (index_n != -1)
	{
		line = ft_substr(stash, 0, index_n);
		return (line);
	}
	if (stash[0] == '\0')
	{
		return (NULL);
	}
	line = ft_substr(stash, 0, ft_strlen(stash));
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		index_n;

	index_n = size_new_line(stash);
	if (index_n == -1)
		return (free(stash), NULL);
	new_stash = ft_substr(stash, index_n, (ft_strlen(stash) - index_n));
	if (!new_stash)
		return (free(stash), NULL);
	free(stash);
	stash = new_stash;
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = ft_calloc(1, sizeof(char));
		if (!stash[fd])
			return (NULL);
	}
	stash[fd] = read_file(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	line = extract_line(stash[fd]);
	if (line == NULL)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
