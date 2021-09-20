/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: zachary <zachary@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 12:45:39 by zachary       #+#    #+#                 */
/*   Updated: 2021/02/24 05:41:56 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*test;

	str = (unsigned char *)dest;
	test = (unsigned char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			str[n - 1] = test[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
