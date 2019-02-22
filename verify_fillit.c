/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verify_fillit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:39:51 by rcorke         #+#    #+#                */
/*   Updated: 2019/02/20 17:01:35 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	verify_square(char *str)
{
	int x;
	int z;
	int validcount;

	z = 0;
	x = 0;
	validcount = 0;
	while (str[x] != '\0' && str[x] != '#' && x < 21)
		x++;
	if (str[x] == '#')
	{
		if (str[x + 1] && str[x + 1] == '#')
			validcount++;
		if (str[x + 5] && str[x + 5] == '#')
			validcount++;
		if (str[x + 6] && str[x + 6] == '#')
			validcount++;
	}
	else if (str[x] == '\0')
		return (0);
	if (validcount == 3)
		return (1);
	return (0);
}

static int	verify_hash(char *str, int validcount, int total_tets)
{
	int x;
	int z;

	z = 0;
	x = 0;
	while (str[x] != '\0' && z < total_tets)
	{
		while (x < ((z + 1) * 21) && str[x] != '\0')
		{
			while (str[x] != '#' && str[x] != '\0' && (x < ((z + 1) * 20)))
				x++;
			if (str[x] == '#' && (str[x + 1] == '#'))
				validcount++;
			if (str[x + 5] && (x + 5 < ((z + 1) * 21)) && str[x + 5] == '#')
				validcount++;
			x++;
		}
		if (validcount < 3 || validcount > 4 || (validcount == 4 && \
		verify_square(&str[x - 21]) != 1))
			return (0);
		validcount = 0;
		z++;
	}
	return (1);
}

static int	verify_dots(char *str, int x, int y, int dots)
{
	while (str[x] != '\0')
	{
		y = x + 20;
		while (x < y && str[x] != '\0')
		{
			if (str[x] == '.' || str[x] == '#')
				dots++;
			else if (str[x] == '\n' && dots == 4)
				dots = 0;
			else if (str[x] == '\n' && dots != 4)
				return (0);
			x++;
		}
		if (str[x] == '\0' && x == y)
			return (1);
		if (str[x] != '\n')
			return (0);
		x++;
	}
	return (1);
}

static int	str_verify_fillit(char *str)
{
	int x;
	int hashcount;
	int newlinecount;

	hashcount = 0;
	newlinecount = 0;
	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] != '#' && str[x] != '.' && str[x] != '\n')
		{
			return (0);
		}
		if (str[x] == '#')
			hashcount++;
		if (str[x] == '\n')
			newlinecount++;
		x++;
	}
	if (hashcount % 4 != 0 || ((x + 1) % 21 != 0))
		return (0);
	if ((((x + 1) - (x / 21)) / (newlinecount + 1) != 4))
		return (0);
	return (1);
}

int			verify_1d_array(char *str)
{
	int total_tets;

	if (str_verify_fillit(str) != 1)
		return (0);
	if (verify_dots(str, 0, 0, 0) != 1)
		return (0);
	total_tets = (ft_strlen(str) + 1) / 21;
	if (verify_hash(str, 0, total_tets) != 1)
		return (0);
	return (1);
}
