/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:59:06 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/28 13:57:59 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	parser(argv, &stack_a);
	print_stack(stack_a);
	ft_lstclear(&stack_a, del);
	return (0);
}
