/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:40:20 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/27 17:05:07 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_splitted(char **arg_splitted, t_stack *stack_a)
{
	int		k;
	int		num;
	t_node	*new_node;

	k = 0;
	while (arg_splitted[k])
	{
		if (!is_valid_num(arg_splitted[k]))
			return (free_split(arg_splitted), 0);
		if (!ft_atol_ps(arg_splitted[k], &num))
			return (free_split(arg_splitted), 0);
		if (has_duplicate(stack_a, num))
			return (free_split(arg_splitted), 0);
		new_node = init_node(num);
		if (new_node == NULL)
			return (free_split(arg_splitted), 0);
		push_bottom(stack_a, new_node);
		k++;
	}
	return (1);
}

int	parser(int argc, char *argv[], t_stack *stack_a)
{
	int		i;
	char	**arg_splitted;

	i = 1;
	init_stack(stack_a, 'A');
	while (i < argc)
	{
		arg_splitted = ft_split(argv[i], ' ');
		if (!arg_splitted)
			return (0);
		if (!check_splitted(arg_splitted, stack_a))
			return (0);
		i++;
		free_split(arg_splitted);
	}
	return (1);
}
