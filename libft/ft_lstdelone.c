/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:10:31 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/05 17:12:57 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
// int main ()
// {
// 	t_list *head;
// 	head = ft_lstnew("hello");
// 	ft_lstadd_back(&head, ft_lstnew("world"));
// 	ft_lstadd_back(&head, ft_lstnew("every"));
// 	ft_lstadd_back(&head, ft_lstnew("every2"));
// 	ft_lstadd_back(&head, ft_lstnew("every3"));
// 	ft_lstadd_back(&head, ft_lstnew("every4"));
// 	ft_lstadd_back(&head, ft_lstnew("every5"));
// 	t_list* tmp = head;
// 	while (tmp)
// 	{
// 		printf("%s ",(char*)tmp->content);
// 		tmp = tmp->next; 
// 	}
// 	printf("%s", (char *)head->content);
// }