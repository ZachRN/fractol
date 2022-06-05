/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pointer_p.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 19:32:33 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/06 19:32:33 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_write(va_list ap)
{
	int			rvalue;
	__uint64_t	mem;

	rvalue = 0;
	mem = va_arg(ap, __uint64_t);
	write(1, "0x", 2);
	rvalue = 2 + ft_putnbr_base(mem, 0, 16);
	return (rvalue);
}
