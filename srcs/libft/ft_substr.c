/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 15:07:28 by znajda        #+#    #+#                 */
/*   Updated: 2021/01/04 05:09:18 by zachary       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	x;

	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL || s == NULL)
		return (NULL);
	x = ft_strlen(s);
	if (start >= x)
	{
		str[0] = '\0';
		return (str);
	}
	while (start < x && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
