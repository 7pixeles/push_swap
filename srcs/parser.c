/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-02 09:40:20 by ayucarre          #+#    #+#             */
/*   Updated: 2025-12-02 09:40:20 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack(t_list **stack_a, long int nbr)
{
	t_list	*aux_stack;
	t_list	*t_list_new;
	int		*value;

	value = malloc(sizeof(int));
	if (!value)
		exit(1);
	*value = (int)nbr;
	t_list_new = ft_lstnew(value);
	aux_stack = *stack_a;
	while (aux_stack)
	{
		if (*(int *)t_list_new->content == *(int *)aux_stack->content)
		{
			ft_printf("Duplicate value: %d\n", *(int *)aux_stack->content);
			free(value);
			free(t_list_new);
			exit(1);
		}
		aux_stack = aux_stack->next;
	}
	ft_lstadd_back(stack_a, t_list_new);
}

void	parser(char *argv[], t_list **stack_a)
{
	int			i;
	int			j;
	char		**split_arg;
	long int	nbr;

	i = 1;
	while (argv[i])
	{
		split_arg = ft_split(argv[i], ' ');
		if (split_arg[0] == NULL)
		{
			ft_printf("Error\n");
			exit(1);
		}
		j = 0;
		while (split_arg[j])
		{
			nbr = ft_long_atoi(split_arg[j]);
			add_to_stack(stack_a, nbr);
			j++;
		}
		i++;
		free_split (split_arg);
	}
}
