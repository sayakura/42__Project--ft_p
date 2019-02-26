# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpeng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 01:46:46 by qpeng             #+#    #+#              #
#    Updated: 2018/11/25 05:40:58 by qpeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -c -Wall -Werror -Wextra

HEADER = libft.h

SRCS = ft_strrchr.c\
		ft_putstr.c\
		ft_strcmp.c\
		ft_strlcat.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strsplit.c\
		ft_strncpy.c\
		ft_lstmap.c\
		ft_lstadd.c\
		ft_striter.c\
		ft_strstr.c\
		ft_isdigit.c\
		ft_lstappend.c\
		ft_putnbr.c\
		ft_memccpy.c\
		ft_strdel.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_putstr_fd.c\
		ft_lstiter.c\
		ft_lstdelone.c\
		ft_toupper.c\
		ft_strcpy.c\
		ft_lstnew.c\
		ft_strdup.c\
		ft_putnbr_fd.c\
		ft_strcut.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_putendl_fd.c\
		ft_memdel.c\
		ft_strnstr.c\
		ft_putchar.c\
		ft_isascii.c\
		ft_strlen.c\
		ft_strsub.c\
		ft_strnew.c\
		ft_memalloc.c\
		ft_putendl.c\
		ft_itoa.c\
		ft_lstsize.c\
		ft_strncmp.c\
		ft_strtrim.c\
		ft_strequ.c\
		ft_putchar_fd.c\
		ft_memset.c\
		ft_isalpha.c\
		ft_tolower.c\
		ft_strnequ.c\
		ft_strjoin.c\
		ft_atoi.c\
		ft_strclr.c\
		ft_strmapi.c\
		ft_isprint.c\
		ft_lstdel.c\
		ft_strchr.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strnlen.c\
		ft_errorexit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(GREEN)LIBFT ✓ Created libft.a"

$(OBJS): $(SRCS)
	gcc $(CFLAGS) -I=$(HEADER) $(SRCS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
