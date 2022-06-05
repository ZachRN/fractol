/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 19:33:19 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/06 19:33:20 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define HEX "0123456789abcdef"

int		ft_printf(const char *str, ...);

/* All Specifier Functions */
int		int_write(va_list ap);
int		char_write(va_list ap);
int		str_write(va_list ap);
int		pointer_write(va_list ap);
int		uint_write(va_list ap);
int		hex_write(va_list ap, char x);
int		percent_write(void);
/* Helper Functions */
void	put_char(const char c);
int		ft_putnbr_base(__uint64_t num, int cap, int base);

#endif
