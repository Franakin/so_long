/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:49:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:49:41 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		ft_lstclear(&ret, del);
		return (NULL);
	}
	ret = new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&ret, new);
	}
	return (ret);
}
