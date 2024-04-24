/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:57:44 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/11/03 12:48:52 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;
	t_list	*current_node;

	if (lst)
	{
		current_node = *lst;
		while (current_node)
		{
			next_node = current_node->next;
			ft_lstdelone(current_node, del);
			current_node = next_node;
		}
		*lst = NULL;
	}
}
