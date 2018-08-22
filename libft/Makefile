# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srabah <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 14:07:29 by srabah            #+#    #+#              #
#    Updated: 2015/02/13 19:00:28 by srabah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	Library output
NAME = libft.a

#	GCC flags
CFLAGS = -Werror
ALL_CFLAGS = -Wall -Wextra $(CFLAGS)

#	Includes directory
INC_DIR = includes/
CPPFLAGS = -iquote $(INC_DIR)

#	Ojects/Sources directories
OBJS_DIR = .
SRCS_DIR = .
VPATH = .

#	Input/Output functions
F_IO = ft_putchar ft_putchar_fd ft_putnbr ft_putendl ft_putnbr_fd ft_putstr ft_putstr_fd ft_putendl_fd

#	List functions
F_LST = ft_lstnew ft_lstdel ft_lstdelone ft_lstadd ft_lstiter ft_lstmap

#	Memory functions
F_MEM = ft_bzero ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy\
		ft_memdel ft_memmove ft_memset

#	String functions
F_STR =	ft_atoi ft_itoa ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy\
		ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin\
		ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp\
		ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strsplit\
		ft_strrev ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper

#	Check functions
F_CHECKS =	ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_islower\
			ft_isprint ft_isupper ft_isspace get_next_line

#	SRCS paths
SRCS = $(addsuffix .c, $(F_IO))
SRCS += $(addsuffix .c, $(F_LST))
SRCS += $(addsuffix .c, $(F_MEM))
SRCS += $(addsuffix .c, $(F_STR))
SRCS += $(addsuffix .c, $(F_CHECKS))

#	OBJS paths
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) rcus $(NAME) $(OBJS)
	@echo "Terminée"

$(OBJS_DIR)/%.o: %.c $(INC_DIR)/libft.h
	@$(CC) $(ALL_CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
