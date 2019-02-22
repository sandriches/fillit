/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   field.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 17:05:12 by kpereira       #+#    #+#                */
/*   Updated: 2019/02/20 18:05:38 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**field_creator(int size)
{
	int			i;
	int			j;
	char		**field;

	i = 0;
	j = 0;
	field = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		field[i] = (char *)malloc(sizeof(char) * (size + 1));
		while (j < size)
		{
			field[i][j] = '.';
			j++;
		}
		field[i][j] = 0;
		j = 0;
		i++;
	}
	field[i] = 0;
	return (field);
}

static void		free_field(char **field)
{
	int			x;

	x = 0;
	while (field[x] != 0)
	{
		free(field[x]);
		x++;
	}
	free(field);
}

static void		print_field(char **field)
{
	int			y;

	y = 0;
	while (field[y] != 0)
	{
		ft_putendl(field[y]);
		y++;
	}
}

void			f_to_call(t_fil_list *ttm, int field_size)
{
	char			**field;
	int				result;

	result = 0;
	field = field_creator(field_size);
	while (result != 1)
	{
		result = loop_array(field, ttm, 0, 0);
		if (result == 0)
		{
			field_size++;
			free_field(field);
			field = field_creator(field_size);
		}
	}
	if (result == 1)
	{
		print_field(field);
		free_field(field);
	}
}
