/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:17:19 by ncsomori          #+#    #+#             */
/*   Updated: 2021/11/30 09:17:23 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lstfree(t_list *alst)
{
	t_list	*tmp;

	while (alst != NULL)
	{
		tmp = alst;
		alst = alst->next;
		tmp->content_size = 0;
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
	}
	alst = NULL;
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	new_lst = ft_lstnew(temp->content, temp->content_size);
	if (!new_lst)
		return (NULL);
	head = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = f(lst);
		new_lst->next = ft_lstnew(temp->content, temp->content_size);
		if (!new_lst->next)
			return (ft_lstfree(head));
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (head);
}
