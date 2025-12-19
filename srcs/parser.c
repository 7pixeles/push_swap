/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:40:20 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/19 19:38:37 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	parser(int argc, char *argv[], t_stack *stack_a)
{
	int i;
	int	k;
	char **arg_splitted;
	int	num;

	t_node	*new_node;
	i = 1;
	init_stack(stack_a, 'a');
	while (i < argc)
	{
		arg_splitted = ft_split(argv[i], ' ');
		if (!arg_splitted)
			return (0);

		//Sepparar en otra función
		k = 0;
		while (arg_splitted[k])
		{
			if(!is_valid_num(arg_splitted[k]))
				return(free_split(arg_splitted), 0);
			if(!ft_atol_ps(arg_splitted[k], &num))
				return(free_split(arg_splitted), 0);
			if(has_duplicate(stack_a, num))
				return(free_split(arg_splitted), 0);
			new_node = init_node(num);
			if (new_node == NULL)
				return(free_split(arg_splitted), 0);
			push_bottom(stack_a, new_node);
			k++;
		}
		i++;
		free_split(arg_splitted);
	}
	return (1);
}
