/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/06 14:25:32 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/06 14:25:34 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((a[i] == b[i]) && (a[i] != '\0' && b[i] != '\0') && (i < len))
	{
		i++;
	}
	if (i < len)
		return (a[i] - b[i]);
	return (0);
}

int	fractol_atoi(char *str, int *numInput)
{
	int			i;
	long int	value;

	i = 1;
	value = 0;
	if (str[i] == '-')
		return (-1);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		if (value > 2147483647 || value * -1 < -2147483648)
			return (-1);
		i++;
	}
	if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '\0'))
		return (-1);
	*numInput = (int)value;
	return (1);
}
