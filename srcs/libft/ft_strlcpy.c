/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: zachary <zachary@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 18:04:10 by zachary       #+#    #+#                 */
/*   Updated: 2021/02/24 05:44:21 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst)
		return ((size_t)(NULL));
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
