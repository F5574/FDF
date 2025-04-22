/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:17:54 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/05 16:00:55 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*buf;

	if (!*lst)
		return ;
	cur = *lst;
	while (cur)
	{
		buf = cur->next;
		del(cur->content);
		free(cur);
		cur = buf;
	}
	*lst = NULL;
}
