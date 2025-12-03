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


void		free_split(char **s);
void		print_stack(t_list *stack);
void		print_stacks(t_list *stack_a, t_list *stack_b);


/* -- ELIMINAR ANTES DE ENTREGAR -- */
void		pretty_stack(t_list *stack_a, t_list *stack_b);


void		del(void *content);

/*-----------------------*/
/*--------SWAP-----------*/
/*-----------------------*/
void		swap_sa(t_list **stack_a);
void		swap_sb(t_list **stack_b);
void		swap_ss(t_list **stack_a, t_list **stack_b);

/*-----------------------*/
/*--------PUSH-----------*/
/*-----------------------*/
void		push_pa(t_list **stack_b, t_list **stack_a);
void		push_pb(t_list **stack_a, t_list **stack_b);

/*-----------------------*/
/*--------ROTATE---------*/
/*-----------------------*/
void		rotate_ra(t_list **stack_a);
void		rotate_rb(t_list **stack_b);
void		rotate_rr(t_list **stack_a, t_list **stack_b);

/*-----------------------*/
/*----REVERSE ROTATE-----*/
/*-----------------------*/
void		reverse_rra(t_list **stack_a);
void		reverse_rrb(t_list **stack_b);
void		reverse_rrr(t_list **stack_a, t_list **stack_b);


long int	ft_long_atoi(char *nptr);
void		add_to_stack(t_list **stack_a, long int nbr);
void		parser(char *argv[], t_list **stack_a);

#endif 