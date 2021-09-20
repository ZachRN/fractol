/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: zachary <zachary@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 22:30:11 by zachary       #+#    #+#                 */
/*   Updated: 2021/02/24 05:39:40 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;

	if (!*lst)
		return ;
	if (del)
	{
		while (*lst)
		{
			clear = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = clear;
		}
	}
	return ;
}
