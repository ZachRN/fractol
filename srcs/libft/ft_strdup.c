/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 09:45:41 by znajda        #+#    #+#                 */
/*   Updated: 2021/01/17 21:54:21 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		strlen;
	int		i;

	strlen = ft_strlen(s);
	str = malloc(sizeof(char) * (strlen + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < strlen)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
