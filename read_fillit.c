/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_fillit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:42:54 by rcorke         #+#    #+#                */
/*   Updated: 2019/02/20 18:25:49 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int				*change_array(int *array)
{
	int i;
	int y;
	int x;

	i = 2;
	y = array[0];
	x = array[1];
	while (i < 8)
	{
		if (array[i] < y)
			y = array[i];
		if (array[i + 1] < x)
			x = array[i + 1];
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		array[i] = array[i] - y;
		array[i + 1] = array[i + 1] - x;
		i += 2;
	}
	return (array);
}

static int				*get_coords(char *str, int x, int z, int coord1)
{
	int coord2;
	int *rtnarray;

	coord2 = 0;
	rtnarray = (int *)malloc(sizeof(int) * 8);
	while (x < 21 && str[x] != '\0')
	{
		if (str[x] == '\n')
		{
			coord2 = -1;
			coord1++;
		}
		else if (str[x] == '#')
		{
			rtnarray[z] = coord1;
			z++;
			rtnarray[z] = coord2;
			z++;
		}
		coord2++;
		x++;
	}
	return (change_array(rtnarray));
}

static t_fil_list		*read_start(int fd, char letter, int x, int ret)
{
	char		*buffer;
	t_fil_list	*head;
	t_fil_list	*list;
	int			total_tets;
	int			*intarray;

	list = create_struct(0, 0);
	buffer = (char *)malloc(sizeof(char) * 548);
	ret = read(fd, buffer, 547);
	buffer[ret] = '\0';
	if (verify_1d_array(buffer) == 0 || ret > 546)
		return (0);
	total_tets = (ft_strlen(buffer) + 1) / 21;
	while (x < total_tets)
	{
		intarray = get_coords(&buffer[x * 21], 0, 0, 0);
		head = list_fillit(intarray, &list, letter);
		free(intarray);
		letter++;
		x++;
	}
	free(list);
	free(buffer);
	return (head);
}

static void				free_list(t_fil_list *head)
{
	t_fil_list *iterate;
	t_fil_list *tmp;

	iterate = head;
	while (iterate->next)
	{
		tmp = iterate;
		iterate = iterate->next;
		free(tmp->coords);
		free(tmp);
	}
	tmp = iterate;
	iterate = iterate->next;
	free(tmp->coords);
	free(tmp);
}

int						main(int argc, char **argv)
{
	int			fd;
	t_fil_list	*head;

	if (argc != 2)
	{
		ft_putstr("usage: fillit tetrimino_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	head = read_start(fd, 'A', 0, 0);
	if (!head)
	{
		ft_putstr("error\n");
		return (0);
	}
	f_to_call(head, 1);
	free_list(head);
}
