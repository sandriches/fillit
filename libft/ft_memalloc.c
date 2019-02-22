/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 15:58:30 by rcorke        #+#    #+#                 */
/*   Updated: 2019/01/21 16:45:14 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	x;

	x = 0;
	str = (char *)malloc(sizeof(size_t) * size);
	if (str == NULL)
		return (NULL);
	while (x < size)
		str[x++] = '\0';
	return (str);
}
