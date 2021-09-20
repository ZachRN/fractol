/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 08:37:50 by znajda        #+#    #+#                 */
/*   Updated: 2021/02/24 05:41:37 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (*str != *str2)
			break ;
		str++;
		str2++;
		n--;
	}
	return (*str - *str2);
}
