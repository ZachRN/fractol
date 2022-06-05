/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   uint_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 19:32:39 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/06 19:32:39 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	uint_write(va_list ap)
{
	unsigned int	num;
	int				rvalue;

	num = va_arg(ap, unsigned int);
	rvalue = ft_putnbr_base(num, 0, 10);
	return (rvalue);
}
