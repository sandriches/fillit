/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:32:38 by kpereira       #+#    #+#                */
/*   Updated: 2019/02/20 18:01:19 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_free(char **field, t_fil_list *ttm, int y, int x)
{
	int			len;

	len = ft_strlen(field[0]);
	if ((y + (ttm->coords[0])) >= len || (y + (ttm->coords[2])) >= len ||
		(y + (ttm->coords[4])) >= len || (y + (ttm->coords[6])) >= len ||
		(x + (ttm->coords[1])) >= len || (x + (ttm->coords[3])) >= len ||
		(x + (ttm->coords[5])) >= len || (x + (ttm->coords[7])) >= len)
		return (0);
	else if (field[y + (ttm->coords[0])][x + (ttm->coords[1])] == '.' &&
		field[y + (ttm->coords[2])][x + (ttm->coords[3])] == '.' &&
		field[y + (ttm->coords[4])][x + (ttm->coords[5])] == '.' &&
		field[y + (ttm->coords[6])][x + (ttm->coords[7])] == '.')
		return (1);
	else
		return (0);
}

static char		**write_on_array(char **field, t_fil_list *ttm, int y, int x)
{
	field[y + (ttm->coords[0])][x + (ttm->coords[1])] = ttm->letter;
	field[y + (ttm->coords[2])][x + (ttm->coords[3])] = ttm->letter;
	field[y + (ttm->coords[4])][x + (ttm->coords[5])] = ttm->letter;
	field[y + (ttm->coords[6])][x + (ttm->coords[7])] = ttm->letter;
	return (field);
}

static char		**remove_from_array(char **field, t_fil_list *ttm, int y, int x)
{
	field[y + (ttm->coords[0])][x + (ttm->coords[1])] = '.';
	field[y + (ttm->coords[2])][x + (ttm->coords[3])] = '.';
	field[y + (ttm->coords[4])][x + (ttm->coords[5])] = '.';
	field[y + (ttm->coords[6])][x + (ttm->coords[7])] = '.';
	return (field);
}

int				loop_array(char **field, t_fil_list *ttm, int y, int x)
{
	if (ttm == 0)
		return (1);
	while (field[y] != 0)
	{
		while (field[y][x] != 0)
		{
			if (is_free(field, ttm, y, x) == 1)
			{
				field = write_on_array(field, ttm, y, x);
				if (loop_array(field, ttm->next, 0, 0) == 1)
				{
					return (1);
				}
				field = remove_from_array(field, ttm, y, x);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}
