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
void		del(void *content);
long int	ft_long_atoi(char *nptr);
void		add_to_stack(t_list **stack_a, long int nbr);
void		parser(char *argv[], t_list **stack_a);

#endif 