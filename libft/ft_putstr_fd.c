/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 13:45:43 by rcorke        #+#    #+#                 */
/*   Updated: 2019/01/24 15:39:04 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int x;

	x = 0;
	if (s)
	{
		while (s[x] != '\0')
			ft_putchar_fd(s[x++], fd);
	}
}
