/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 19:32:14 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/06 19:32:15 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(const char c)
{
	write(1, &c, 1);
}

int	char_write(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	put_char(c);
	return (1);
}
