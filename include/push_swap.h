/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:41 by ayucarre          #+#    #+#             */
/*   Updated: 2026/01/04 23:25:10 by ayua             ###   ########.fr       */
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

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				dir;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int			size;
	char		name;
	t_node		*top;
	t_node		*bottom;
}				t_stack;

/*
* 	INICIALIZATION NODE & PARAMS 
*/
t_node	*init_node(int value);
bool	calc_index(t_stack *stack);
void	calc_pos(t_stack *stack);

/*
* 	INICIALIZATION STACKS
*/
void	init_stack(t_stack *stack, char name);
void	clear_stack(t_stack *stack);
int		stack_is_sorted(t_stack *stack_a);
int		calc_size(t_stack *stack);

/*
* 	STACK BASIC MOVEMENTS
*/
void	push_top(t_stack *stack, t_node *node);
void	push_bottom(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);

//--- TOOLS
int		*copy_stack_to_array(t_stack *stack);
void	sort_array(int *array, int size);
void	exit_code(t_stack *a, t_stack *b, int code);

/*
* 	PUSH_SWAP MOVEMENTS
*/
void	push(t_stack *stack_from, t_stack *stack_to);
void	swap_sa(t_stack *stack);
void	swap_sb(t_stack *stack_b);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);
void	rotate_ra(t_stack *stack_a);
void	rotate_rb(t_stack *stack_b);
void	rotate_rr(t_stack *stack_a, t_stack *stack_b);
void	r_rotate_rra(t_stack *stack_a);
void	r_rotate_rrb(t_stack *stack_b);
void	r_rotate_rrr(t_stack *stack_a, t_stack *stack_b);

/*
* 	PARSER
*/
int		parser(int argc, char *argv[], t_stack *stack_a);

//--- PARSER UTILS
int		ft_atol_ps(const char *nptr, int *num);
int		is_valid_num(char *nptr);
int		has_duplicate(t_stack *stack, int nbr);
void	free_split(char **split);

/*
* 	SORT FUNCTIONS
*/
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
//--- SORTING UTILS

int			get_min_pos(t_stack *stack);
int			get_max_index_pos(t_stack *stack);
void		push_min_to_b(t_stack *stack_a, t_stack *stack_b);
void		push_max_to_a(t_stack *stack_a, t_stack *stack_b);
void		push_rotate_b(t_stack *stack_a, t_stack *stack_b, int *range);

// TODO En código final, eliminar el pretty stack, tiene función prohibida 
/*
* 	PRINTER
*/
void	print_stack(t_stack *stack);
void	pretty_stack(t_stack *stack_a, t_stack *stack_b);

#endif 

/* 
* 	TESTING CONSOLE
	
	ARG=$(seq -500 800 | shuf -n 20 | tr '\n' ' ')
	./push_swap $ARG
	| ./checker_linux $ARG | wc -l
	./push_swap_visualizer/build/bin/visualizer
*/