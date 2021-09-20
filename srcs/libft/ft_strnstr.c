/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: zachary <zachary@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 13:05:15 by zachary       #+#    #+#                 */
/*   Updated: 2021/02/24 05:45:37 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (small[0] == '\0')
		return ((char *)&big[0]);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((big[i + j] == small[j]) && (i + j < len) && big[i + j] != '\0')
		{
			j++;
			if (small[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
