/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:41 by ayucarre          #+#    #+#             */
/*   Updated: 2026/01/02 18:02:18 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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
	int				cost;
	int				keep;
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
* ····· STACK INITIALIZATION AND CLEARING FUNCTIONS
*/

/*
* 	init_node -> returns a new node with value sent as param
*/
t_node	*init_node(int value);

/*
* 	init_stack -> initializes stack with name sent as param
*/
void	init_stack(t_stack *stack, char name);

/*
* 	clear_stack -> clear from top till last node, then sets defaults values
*/
void	clear_stack(t_stack *stack);

int		stack_is_sorted(t_stack *stack_a);

void	index_node(t_stack *stack);
/*
* ····· STACK BASIC MOVEMENTS
*/
/*
* 	push_top -> Adds an existing node to the top of a stack, updating the size
*/
void	push_top(t_stack *stack, t_node *node);
/*
*	push_bottom -> Adds an existing node to the bottom of a stack,
				   updating the size
*/

void	push_bottom(t_stack *stack, t_node *node);
/*
* 	pop_top -> Extracts the top node of a stack , updating the size
*/
t_node	*pop_top(t_stack *stack);
/*
* 	pop_bottom -> Extracts the bottom node of a stack , updating the size
*/
t_node	*pop_bottom(t_stack *stack);

/*
* ····· PUSH_SWAP MOVEMENTS
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

/*--- printer.c ---*/
void	print_stack(t_stack *stack);
// TODO En código final, eliminar el pretty stack, tiene función prohibida 
void	pretty_stack(t_stack *stack_a, t_stack *stack_b);

/* ---- exit.c */
void	exit_code(t_stack *a, t_stack *b, int code);

/*
* ····· PARSER
*/

int		parser(int argc, char *argv[], t_stack *stack_a);

/*--- PARSER UTILS -------*/
int		ft_atol_ps(const char *nptr, int *num);
int		is_valid_num(char *nptr);
int		has_duplicate(t_stack *stack, int nbr);
void	free_split(char **split);

/*
* ····· SORTING
*/
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_heap(t_stack *stack_a, t_stack *stack_b);
void	radix_bits(t_stack *stack_a, t_stack *stack_b);
/* void	turk_algo(t_stack *stack_a, t_stack *stack_b); */

/*-----SORTING UTILS-----------*/
void	calc_cost_dir(t_stack *stack, t_node *node);
int		*copy_stack_to_array(t_stack *stack);


// HEAP
int		set_n_index_max(t_stack *stack, int n);
int		set_n_index_min(t_stack *stack, int n);
void	sort_heap_n(t_stack *stack_a, t_stack *stack_b, int size_heap);


int		set_index_max(t_stack *stack);
int		set_index_min(t_stack *stack);
int		is_index_in_top(t_stack *stack, int index);
void	min_moves(t_stack *stack_to, t_stack *stack_from, int index);

#endif 

//ARG=$(seq -500 800 | shuf -n 20 | tr '\n' ' ') ./push_swap $ARG 
// | ./checker_linux $ARG | wc -l
// ARGS="seq -500 800 | shuf -n 5 | tr '\n' ' '";
// ./push_swap $ARGS

// ./push_swap_visualizer/build/bin/visualizer