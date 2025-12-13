/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:42:25 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/13 14:22:20 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	exit_code(t_stack *a, t_stack *b, int code)
{
	if (a)
		clear_stack(a);
	if (b)
		clear_stack(b);
	if (code == ERROR_ARGS || code == ERROR_PARSING
		|| code == STDIN_READ_ERROR)
		write(2, "Error\n", 6);
	exit(code);
}
