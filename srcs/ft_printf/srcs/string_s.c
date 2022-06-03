/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_s.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 19:32:36 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/06 19:32:36 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	str_write(va_list ap)
{
	int		strlen;
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	write(1, str, strlen);
	return (strlen);
}
