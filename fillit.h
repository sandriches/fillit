/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 16:54:56 by rcorke         #+#    #+#                */
/*   Updated: 2019/02/22 13:39:15 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct			s_fil_str
{
	int					*coords;
	char				letter;
	struct s_fil_str	*next;
}						t_fil_list;

t_fil_list				*list_fillit(int *i, t_fil_list **head, char letter);
t_fil_list				*create_struct(int *array, char letter);
void					f_to_call(t_fil_list *ttm, int field_size);
int						verify_1d_array(char *str);
int						loop_array(char **field, t_fil_list *ttm, int y, int x);

#endif
