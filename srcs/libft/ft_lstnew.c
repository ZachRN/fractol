/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: zachary <zachary@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 20:33:12 by zachary       #+#    #+#                 */
/*   Updated: 2021/02/24 05:40:43 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*addnew;

	addnew = (t_list *)malloc(sizeof(t_list));
	if (!addnew)
		return (NULL);
	addnew->content = content;
	addnew->next = NULL;
	return (addnew);
}
