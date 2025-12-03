/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-02 09:40:37 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-02 09:40:37 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		exit(1);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("[Stack A]\n");
	ft_printf("-----\n");
	print_stack(stack_a);
	ft_printf("[Stack B]\n");
	ft_printf("-----\n");
	print_stack(stack_b);
}

/* -- ELIMINAR ANTES DE ENTREGAR -- */
void	pretty_stack(t_list *stack_a, t_list *stack_b)
{
	t_list *tmp_a = stack_a;
	t_list *tmp_b = stack_b;
	
	printf("[Stack A] [Stack B]\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a && tmp_b)
		{
			printf("%5d %10d\n", *(int *)tmp_a->content, *(int *)tmp_b->content);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
		
		else if (tmp_a)
		{
			printf("%5d\n", *(int *)tmp_a->content);
			tmp_a = tmp_a->next;
		}
		else if (tmp_b)
		{
			printf("%5d\n", *(int *)tmp_b->content);
			tmp_b = tmp_b->next;
		}
	}
}

void	del(void *content)
{
	free(content);
}
