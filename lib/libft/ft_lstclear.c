/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:50:19 by ayucarre          #+#    #+#             */
/*   Updated: 2025/11/18 12:14:54 by ayucarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_tmp;

	while (*lst != NULL)
	{
		lst_tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = lst_tmp;
	}
	free(*lst);
	*lst = NULL;
}
