/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:24:41 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/28 16:39:02 by ayua             ###   ########.fr       */
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

/*--- printer.c ---*/
// TODO En código final, eliminar el pretty stack, tiene función prohibida
void		print_stack(t_list *stack);
void		print_stacks(t_list *stack_a, t_list *stack_b);
void		pretty_stack(t_list *stack_a, t_list *stack_b);

/* ---- exit.c */
void	exit_code(t_list *a, t_list *b, int code);

/*---- stack_utils.c ----*/
int		add_to_stack(t_list **stack_a, t_list **t_list_new, long nbr);
int 	is_duplicate_num(t_list **stack_a, long nbr);
/*--------SWAP-----------*/
void		swap_sa(t_list **stack_a);
void		swap_sb(t_list **stack_b);
void		swap_ss(t_list **stack_a, t_list **stack_b);
/*--------PUSH-----------*/
void		push_pa(t_list **stack_b, t_list **stack_a);
void		push_pb(t_list **stack_a, t_list **stack_b);
/*--------ROTATE---------*/
void		rotate_ra(t_list **stack_a);
void		rotate_rb(t_list **stack_b);
void		rotate_rr(t_list **stack_a, t_list **stack_b);
/*----REVERSE ROTATE-----*/
void		reverse_rra(t_list **stack_a);
void		reverse_rrb(t_list **stack_b);
void		reverse_rrr(t_list **stack_a, t_list **stack_b);

/*----PARSER--------------*/

void		free_split(char **s);
int			parser(char *argv[], t_list **stack_a);
int			is_valid_num(char *nptr);


/*-----SORTING------------*/
/*void	sort_3(t_list **stack);
void	sort_5(t_list **stack_a, t_list **stack_b); */
#endif 


//	seq -500 800 | shuf -n 20 | tr '\n' ' '