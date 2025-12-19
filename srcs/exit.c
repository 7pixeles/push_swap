/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:42:25 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/19 19:38:49 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	idx;

	idx = 0;
	if (!split)
		return ;
	while (split[idx])
	{
		free(split[idx]);
		idx++;
	}
	free(split);
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
