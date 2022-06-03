/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex_xX.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 19:32:22 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/06 19:32:22 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_usize(__uint64_t number, int base)
{
	__uint64_t	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= base;
		i++;
	}
	return (i);
}

int	ft_putnbr_base(__uint64_t num, int cap, int base)
{
	char	temp[20];
	int		max;

	max = ft_usize(num, base);
	temp[max] = '\0';
	while ((max - 1) > -1)
	{
		temp[max - 1] = HEX[num % base];
		if (num % base > 9)
			temp[max - 1] -= cap;
		num /= base;
		max--;
	}
	while (temp[max])
	{
		put_char(temp[max]);
		max++;
	}
	return (max);
}

int	hex_write(va_list ap, char x)
{
	int				cap;
	int				rvalue;
	unsigned int	number;

	cap = 0;
	if (x == 'X')
		cap = 32;
	number = va_arg(ap, unsigned int);
	rvalue = ft_putnbr_base(number, cap, 16);
	return (rvalue);
}
