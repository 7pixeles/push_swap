/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:41 by ayucarre          #+#    #+#             */
/*   Updated: 2026/01/04 16:29:21 by ayua             ###   ########.fr       */
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
	int				cost;
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
void	calc_index(t_stack *stack);
void	calc_pos(t_stack *stack);
void	calc_cost(t_stack *stack);

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
/// @brief Busca el nodo con el índice absoluto más bajo
/// @param stack Puntero al stack en el que buscar el nodo
/// @return Puntero al nodo encontrado
t_node	*get_index_min(t_stack *stack);
void	move_n_index(t_stack *stack_from, t_stack *stack_to, int moves);
void	move_n_target(t_stack *stack_from, t_stack *stack_to);
/// @brief Busca en stack el índice más bajo con el menor coste posible
/// @param stack stack en el que buscar
/// @return Puntero al nodo encontrado, NULL si no lo encuentra
t_node *find_target(t_stack *stack);

/// @brief mueve a la parte superior del stack el nodo con el índice más bajo y el coste menor
/// @param stack 
void	move_target_top(t_stack *stack);



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