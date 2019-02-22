/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_fillit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 16:51:05 by rcorke         #+#    #+#                */
/*   Updated: 2019/02/20 18:01:31 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*int_cpy(int *dst, int *src, int len)
{
	int x;

	x = 0;
	while (x < len)
	{
		dst[x] = src[x];
		x++;
	}
	return (dst);
}

static void		add_to_list(t_fil_list **lst, t_fil_list *current)
{
	t_fil_list *tmp;

	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = current;
}

t_fil_list		*create_struct(int *intarray, char letter)
{
	t_fil_list *new;

	new = (t_fil_list *)malloc(sizeof(t_fil_list));
	if (new)
	{
		if (intarray != 0)
		{
			new->coords = (int *)malloc(sizeof(int) * 8);
			new->coords = int_cpy(new->coords, intarray, 8);
		}
		if (letter != 0)
			new->letter = letter;
		new->next = NULL;
		return (new);
	}
	return (0);
}

int				ft_lstlen_fillit(t_fil_list *lst)
{
	int x;

	x = 0;
	while (lst->next != NULL)
	{
		lst = lst->next;
		x++;
	}
	return (x);
}

t_fil_list		*list_fillit(int *intarray, t_fil_list **head, char letter)
{
	t_fil_list	*current;
	t_fil_list	*tmp;
	int			x;

	x = 0;
	current = create_struct(intarray, letter);
	add_to_list(head, current);
	tmp = (*head)->next;
	return (tmp);
}
