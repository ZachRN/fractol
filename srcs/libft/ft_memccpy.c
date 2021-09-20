/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 07:27:44 by znajda        #+#    #+#                 */
/*   Updated: 2021/01/05 09:49:42 by zachary       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*org;
	size_t			i;

	i = 0;
	str = (unsigned char *)dest;
	org = (unsigned char *)src;
	while (n)
	{
		str[i] = org[i];
		if (org[i] == (unsigned char)c)
			return (&str[i + 1]);
		i++;
		n--;
	}
	return (NULL);
}
