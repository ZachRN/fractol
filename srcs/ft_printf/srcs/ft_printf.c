/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 19:32:19 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/06 19:32:20 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifier_write(const char *str, va_list ap, int str_pos)
{
	str_pos++;
	if (str[str_pos] == 'd' || str[str_pos] == 'i')
		return (int_write(ap));
	else if (str[str_pos] == 'c')
		return (char_write(ap));
	else if (str[str_pos] == 's')
		return (str_write(ap));
	else if (str[str_pos] == 'x' || str[str_pos] == 'X')
		return (hex_write(ap, str[str_pos]));
	else if (str[str_pos] == 'p')
		return (pointer_write(ap));
	else if (str[str_pos] == 'u')
		return (uint_write(ap));
	else if (str[str_pos] == '%')
		return (percent_write());
	return (0);
}

static int	string_write(const char *str, int str_pos, int last_pos)
{
	if (str_pos - last_pos)
		write(1, str + last_pos, str_pos - last_pos);
	return (str_pos - last_pos);
}

static int	str_parse(const char *str, va_list ap)
{
	int	rvalue;
	int	str_pos;
	int	last_pos;
	int	flag_write;

	str_pos = 0;
	rvalue = 0;
	flag_write = 0;
	last_pos = 0;
	while (str[str_pos])
	{
		if (str[str_pos] == '%')
		{
			rvalue = rvalue + string_write(str, str_pos, last_pos);
			flag_write = flag_write + specifier_write(str, ap, str_pos);
			str_pos++;
			last_pos = str_pos + 1;
		}
		str_pos++;
	}
	return (rvalue + string_write(str, str_pos, last_pos) + flag_write);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				rvalue;

	va_start(ap, str);
	rvalue = str_parse(str, ap);
	va_end(ap);
	return (rvalue);
}
