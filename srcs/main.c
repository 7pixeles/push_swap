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
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	if (argc < 2)
	{
		return (0);
	}
	parser(argv, &stack_a);
	
	push_pa(&stack_b, &stack_a);
	pretty_stack(stack_a, stack_b);
	ft_lstclear(&stack_a, del);
	ft_lstclear(&stack_b, del);
	return (0);
}
