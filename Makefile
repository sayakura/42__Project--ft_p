# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qpeng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 05:16:16 by qpeng             #+#    #+#              #
#    Updated: 2019/02/24 08:00:54 by qpeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =  -Wall -Werror -Wextra

all: client server

client:
	gcc $(FLAGS) client.c ./libft/libft.a client_do_op.c client_do_op2.c common.c -o client
server:
	gcc $(FLAGS) s.c ./libft/libft.a server_do_op.c server_helper.c common.c -o server
clean:
	rm server client
fclean: clean

re: clean all
