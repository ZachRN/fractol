/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: zachary <zachary@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 19:10:04 by zachary       #+#    #+#                 */
/*   Updated: 2021/02/24 05:39:18 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*toadd;

	if (!*lst)
		*lst = new;
	else
	{
		toadd = ft_lstlast(*(lst));
		toadd->next = new;
	}
}
