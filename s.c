/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:38:31 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/26 12:38:32 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s.h"
#define MAX_CLIENTS 20

char	*g_home_dir;
int		g_port;

int		socket_setup_ip6(void)
{
	int					main_sock;
	struct sockaddr_in6	address;
	int					opt;

	opt = 1;
	if ((main_sock = socket(AF_INET6, SOCK_STREAM, 0)) == 0)
		ft_errorexit("socket failed");
	if (setsockopt(main_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,\
													sizeof(opt)) < 0)
		ft_errorexit("setsockopt failed");
	address.sin6_family = AF_INET6;
	address.sin6_port = htons(g_port);
	address.sin6_addr = in6addr_any;
	if (bind(main_sock, (struct sockaddr *)&address, sizeof(address)) < 0)
		ft_errorexit("bind failed");
	return (main_sock);
}

void	handle_request(int *client_socks, fd_set *fd_list)
{
	int		i;

	i = -1;
	while (++i < MAX_CLIENTS)
		if (FD_ISSET(client_socks[i], fd_list))
			if (!handle_op(client_socks[i]))
			{
				printf("Client disconnected.\n");
				close(client_socks[i]);
				client_socks[i] = 0;
			}
}

void	connection_handler(int master_s, fd_set *fd_list, int *client_socks)
{
	int					connected_s;
	struct sockaddr_in6	address;
	int					addrlen;
	int					i;

	i = -1;
	if (FD_ISSET(master_s, fd_list))
	{
		if ((connected_s = accept(master_s,
			(struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
			ft_errorexit("Accept failed.");
		printf("New connection, socket fd is %d\n", connected_s);
		while (++i < MAX_CLIENTS)
			if (client_socks[i] == 0)
			{
				client_socks[i] = connected_s;
				printf("Adding to list of sockets as %d\n", i);
				break ;
			}
	}
}

void	socket_select_setup(int sock)
{
	fd_set	fd_list;
	int		max_sock;
	int		i;
	int		client_socks[MAX_CLIENTS];

	ft_bzero(client_socks, sizeof(client_socks));
	while (1)
	{
		i = -1;
		FD_ZERO(&fd_list);
		FD_SET(sock, &fd_list);
		max_sock = sock;
		while (++i < MAX_CLIENTS)
		{
			if (client_socks[i] > 0)
				FD_SET(client_socks[i], &fd_list);
			if (client_socks[i] > max_sock)
				max_sock = client_socks[i];
		}
		if (select(max_sock + 1, &fd_list, NULL, NULL, NULL) < 0)
			ft_errorexit("Select error");
		connection_handler(sock, &fd_list, client_socks);
		handle_request(client_socks, &fd_list);
	}
}

int		main(int ac, char **av)
{
	int	socket;

	mkdir("root", 0777);
	chdir("root");
	if (ac > 1)
		g_port = ft_atoi(av[1]);
	else
		g_port = 7777;
	g_home_dir = getcwd(NULL, 200);
	socket = socket_setup_ip6();
	printf("waiting for connection...\n");
	if (listen(socket, 3) < 0)
		ft_errorexit("Listen failed.");
	printf("Listening on port %d \n", g_port);
	socket_select_setup(socket);
	free(g_home_dir);
	return (0);
}
