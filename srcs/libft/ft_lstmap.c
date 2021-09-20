/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/17 16:52:08 by znajda        #+#    #+#                 */
/*   Updated: 2021/05/13 11:25:08 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*savefirst;
	t_list	*toadd;

	if (!lst || !f)
		return (NULL);
	savefirst = NULL;
	while (lst)
	{
		toadd = ft_lstnew(f(lst->content));
		if (!toadd)
		{
			ft_lstclear(&savefirst, del);
			return (NULL);
		}
		else
		{
			lst = lst->next;
			ft_lstadd_back(&savefirst, toadd);
		}
	}
	return (savefirst);
}
