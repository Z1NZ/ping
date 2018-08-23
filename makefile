CC    = clang  -Wall -Wextra -Werror

LDFLAGS	= -I./includes/ -I./libft/includes -lncurses

RM    = rm -f

NAME    = ft_ping

SRC    = main.c\
		ft_error.c\
		ft_in_cksum.c\
		ft_ping.c

OBJS    = $(SRC:.c=.o)
SRCDIR 	= ./srcs/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
all : $(NAME)

$(NAME):
	make -C libft/
	@$(CC) $(SRCS) $(LDFLAGS) -L./libft -lft -o $(NAME) 
clean:
	make clean -C libft/
	@$(RM) $(OBJS) 
fclean: clean
	make fclean -C libft/
	@$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re