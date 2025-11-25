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

int	is_valid_arg(char *argv)
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) != 1)
			return (0);
		else if(argv[i] == '+' || argv[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

char *parse_arg(char *argv)
{

	if (is_valid_arg(argv[i] != 0))
	{
		return ();
	}
	return 
}

int main(int argc, char *argv[])
{
	int i;
	int j; 
	int flag;

	flag = 1;
	char **arg; //argumento en split
	if (argc < 2)
	{
		ft_printf("Error\n");
		return(1);
	}

	i = 1;
	while (i < argc)
	{
		arg = ft_split(argv[i], ' ');
		j = 0;
		while (arg[j])
		{
			flag = parse(arg[j], flag);
			if (flag == 1)
			{
				ft_printf("%s\n", arg[j]);
			}
			else 
			{
		
				exit(1);
			}
			free(arg[j]);
			j++;
		}
		i++;
		free(arg);
	}
}
