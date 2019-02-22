# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcorke <rcorke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/08 16:49:14 by rcorke         #+#    #+#                 #
#    Updated: 2019/02/22 13:40:05 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = read_fillit.c list_fillit.c solver.c field.c verify_fillit.c
LIBRARY = libft/libft.a
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc $(FLAGS) -I./ $(SRCS) $(LIBRARY) -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJS) *~

libclean:
	@make -C libft/ fclean

fclean: clean libclean
	@rm -rf $(NAME)
	@rm -rf *.dSYM

re: fclean all
