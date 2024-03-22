# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkaras <rkaras@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/06 17:25:38 by rkaras        #+#    #+#                  #
#    Updated: 2024/03/20 18:57:28 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = Libft/libft.a
LIBFTDIR = Libft
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SOURCE = main.c \
			command_push.c \
			command_reverse_rotate.c \
			command_rotate.c \
			command_swap.c \
			ft_free.c \
			parsing.c \
			sorting_utils.c \
			sorting.c \
			stack_utils.c \

OBJECTS = $(SOURCE:%.c=%.o)

all: $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJECTS)
		$(CC) $(FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I $(LIBFTDIR)

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJECTS)

fclean:	clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re