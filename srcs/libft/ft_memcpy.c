/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: zachary <zachary@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 20:26:18 by zachary       #+#    #+#                 */
/*   Updated: 2021/01/04 05:39:22 by zachary       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*str;
	char			*str2;
	unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	str = (char *)dest;
	str2 = (char *)src;
	i = 0;
	while (n)
	{
		str[i] = str2[i];
		i++;
		n--;
	}
	return (dest);
}
