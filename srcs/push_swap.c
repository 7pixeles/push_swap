/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:59:06 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/24 17:21:47 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
parse(char *arg_int)
{

} */

int main(int argc, char *argv[])
{
	int i;
	int j;
	char **num;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return(1);
	}

	i = 1;
	while (i < argc)
	{
		num = ft_split(argv[i], ' ');
		j = 0;
		while (num[j])
		{
			ft_printf("%s\n", num[j]);
			free(num[j]);
			j++;
		}
		i++;
		free(num);
	}
}

// **argv -> arg[str[1], str[2], ...]
