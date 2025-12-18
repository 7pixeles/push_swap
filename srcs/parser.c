/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:40:20 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/18 10:12:44 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol_ps(const char	*nptr, int *error_code)
{
	int		i;
	long	n;
	long	sign;

	*error_code = 0;
	sign = 1;
	i = 0;
	n = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = 10 * n + (nptr[i] - '0');
		if ((n * sign) < INT_MIN || (n * sign) > INT_MAX)
			return (*error_code = 1, 0);
		i++;
	}
	return (n * sign);
}

int	is_valid_num(char *nptr)
{
	int i;

	i = 0;
	while (nptr[i])
	{
		if (nptr[i] == '+' || nptr[i] == '-')
		{
			if (!ft_isdigit(nptr[i + 1]))
				return (0);
		}
		else if (!ft_isdigit(nptr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_args(char *argv[], int *error_code)
{
	int	i_arg;
	int i_token;
	int token_count;
	char **split_tokens;
	
	*error_code = 0;
	i_arg = 1;
	token_count = 0;
	while (argv[i_arg])
	{
		split_tokens = ft_split(argv[i_arg], ' ');
		if (!split_tokens)
			return (*error_code = 1, 0);
		if (split_tokens[0] == NULL)
			return (free_split(split_tokens), *error_code = 1, 0);	
		i_token = 0;
		while (split_tokens[i_token])
			i_token++;
		token_count += i_token;
		i_arg++;
		free_split(split_tokens);
	}
	return (token_count);
}

int	copy_tokens(char **dest, int *i_dest, char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		dest[*i_dest] = ft_strdup(tokens[i]);
		if (!dest[*i_dest])
			return (0);
		(*i_dest)++;
		i++;
	}
}
char	**flatten_args(char *argv[], int *error_code)
{
	int		i_args;
	int		i_flat;
	char	**tokens;
	char	**flat_args;

	i_args = 1;
	i_flat = 0;
	*error_code = 0;
	flat_args = malloc((count_args(argv, error_code) + 1) * sizeof(char *));
	if (!flat_args)
		return (*error_code = 1, NULL);
	while (argv[i_args])
	{
		tokens = ft_split(argv[i_args], ' ');
		if (!tokens || !tokens[0] || !copy_tokens(flat_args, &i_flat, tokens))
		{
			free_split(tokens);
			free_partial_split(flat_args, i_flat);
			return (*error_code = 1, NULL);
		}
		free_split(tokens);
		i_args++;
	}
	flat_args[i_flat] = NULL;
	return (flat_args);
}

int	parser(char *argv[], t_list **stack_a) 
{
	int i;
	char **arg;
	long int nbr;
	int error_code;
	
	error_code = 0;
	i = 0; 
	arg = flatten_args(argv, error_code);
	if (!arg) 
		return (free_split(arg), 0);
	while (arg[i])
	{
		nbr = ft_atol_ps(arg[i], &error_code); 
		if (error_code)
			return (free_split(arg), 0);
		if (!is_valid_num(arg[i]))
			return (free_split(arg), 0);
		if (!is_duplicate_num(stack_a, nbr))
			return (free_split(arg), 0);
		i++; 
	}
	free_split (arg); 
	return (1); 
}
