/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 07:56:48 by znajda        #+#    #+#                 */
/*   Updated: 2021/01/05 12:28:41 by zachary       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)s;
	while (n)
	{
		if (temp[i] == (unsigned char)c)
			return (&temp[i]);
		i++;
		n--;
	}
	return (NULL);
}
