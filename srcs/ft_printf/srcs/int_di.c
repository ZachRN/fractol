/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_di.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 19:32:26 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/06 19:32:27 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		put_char('-');
		ft_putnbr(n * -1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		put_char(n + '0');
}

static int	num_size(int number)
{
	int	size;

	size = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= 10;
		size++;
	}
	return (size);
}

int	int_write(va_list ap)
{
	int	rvalue;
	int	number;

	number = va_arg(ap, int);
	rvalue = num_size(number);
	if (number < 0)
		rvalue++;
	ft_putnbr(number);
	return (rvalue);
}
