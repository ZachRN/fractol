/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 11:02:37 by znajda        #+#    #+#                 */
/*   Updated: 2021/02/24 05:37:39 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*memory;

	if (nmeb == 0 || size == 0)
	{
		nmeb = 1;
		size = 1;
	}
	memory = malloc(nmeb * size);
	if (memory)
		ft_bzero(memory, (nmeb * size));
	return (memory);
}
