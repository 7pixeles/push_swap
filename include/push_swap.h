/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:41 by ayucarre          #+#    #+#             */
/*   Updated: 2025/12/18 10:05:49 by ayua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

# define ERROR_PARSING 2
# define ERROR_SORTING 3
# define ALREADY_SORTED 4
# define ERROR_ARGS 5
# define STDIN_READ_ERROR 6

typedef struct		s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct	s_stack
{
	int			size;
	char		name;
	t_node		*top;
	t_node		*bottom;
}				t_stack;

/*
* ····· STACK INITIALIZATION AND CLEARING FUNCTIONS
*/

/*
* 	new_node -> returns a new node with value sent as param
*/
t_node	*new_node(int value);

/*
* 	init_stack -> initializes stack with name sent as param
*/
void	init_stack(t_stack *stack, char name);

/*
* 	clear_stack -> clear from top till last node, then sets defaults values
*/
void	clear_stack(t_stack *stack);


/*
* ····· STACK BASIC MOVEMENTS
*/
/*
* 	push_top -> Adds an existing node to the top of a stack, updating the size
*/
void push_top(t_stack *stack, t_node *node);
/*
* 	push_bottom -> Adds an existing node to the bottom of a stack, updating the size
*/
void push_bottom(t_stack *stack, t_node *node);
/*
* 	pop_top -> Extracts the top node of a stack , updating the size
*/
t_node *pop_top(t_stack *stack);
/*
* 	pop_bottom -> Extracts the bottom node of a stack , updating the size
*/
t_node *pop_bottom(t_stack *stack);


/*--- printer.c ---*/
// TODO En código final, eliminar el pretty stack, tiene función prohibida
void		print_stack(t_list *stack);
void		print_stacks(t_list *stack_a, t_list *stack_b);
void		pretty_stack(t_list *stack_a, t_list *stack_b);

/* ---- exit.c */
void	exit_code(t_stack *a, t_stack *b, int code);

/*---- stack_utils.c ----*/
int 	is_duplicate_num(t_list **stack_a, long nbr);


/*----PARSER--------------*/
long int	ft_atol_ps(const char	*nptr, int *error_code);
int			is_valid_num(char *nptr);
int			is_duplicate_num(t_list **stack_a, long nbr);
void		free_split(char **split);
void		free_partial_split(char **split, int count);
int			parser(char *argv[], t_list **stack_a);


/*-----SORTING------------*/
/*void	sort_3(t_list **stack);
void	sort_5(t_list **stack_a, t_list **stack_b); */
#endif 


//	seq -500 800 | shuf -n 20 | tr '\n' ' '