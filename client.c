/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 02:10:16 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/26 02:10:19 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "common.h"

int		bounus_prompt(int sock, char *buf)
{
	if ((ft_strncmp(buf, "mkdir ", 6)) == 0)
		do_mkdir(sock, buf + 6);
	else if ((ft_strncmp(buf, "rmdir ", 6)) == 0)
		do_rmdir(sock, buf + 6);
	else if ((ft_strncmp(buf, "unlink ", 7)) == 0)
		do_unlink(sock, buf + 7);
	else if ((ft_strncmp(buf, "lls", 3)) == 0)
		do_lls();
	else if ((ft_strncmp(buf, "lcd ", 4)) == 0)
		do_lcd(buf + 4);
	else if ((ft_strncmp(buf, "lpwd", 3)) == 0)
		do_lpwd();
	else if ((ft_strncmp(buf, "lmkdir ", 7)) == 0)
		mkdir(buf + 7, 0766);
	else
		return (0);
	return (1);
}

int		prompt(int sock)
{
	char    *buf;

	buf = get_input();
	if ((ft_strncmp(buf, "ls", 2)) == 0 &&
		(buf[2] == '\0' ||  buf[2] == ' '))
		do_ls(sock, buf + 3);
	else if ((ft_strncmp(buf, "cd", 2)) == 0) 
		do_cd(sock, buf);
	else if ((ft_strncmp(buf, "get ", 4)) == 0)
		do_get(sock, buf + 4);
	else if ((ft_strncmp(buf, "put ", 4)) == 0)
		do_put(sock, buf + 4);
	else if ((ft_strncmp(buf, "pwd", 3)) == 0)
		do_pwd(sock);
	else if (bounus_prompt(sock, buf))
		;
	else if ((ft_strncmp(buf, "quit", 4)) == 0)
	{
		close(sock);
		return (0);
	}
	else
		printf("command not found: %s\n", buf);
	return (1);
}

void	socket_setup(char *host, int port)
{

	int					sock;
	struct sockaddr_in	servaddr;

	if (ft_strcmp(host, "localhost") == 0)
		host = "127.0.0.1";
	printf("\x1b[33mConnecting...\x1b[0m %s %d\n", host, port);
	sock = socket(AF_INET, SOCK_STREAM, 0); 
	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr(host); 
	servaddr.sin_port = htons(port); 
	if (connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
		ft_errorexit("\x1b[31mConnection Failed. \n\x1b[0m");
	else
		while (1)
			if (!prompt(sock))
				break ;
	close(sock);
}

int		main(int ac, char **av)
{
	if (ac != 3)
		ft_errorexit("Need to specify the ip and the port.");
	printf("================================================\n");
	printf("|                                              |\n");
	printf("|                  FTP 1.0.0                   |\n");
	printf("|                Author: \x1b[35mQpeng\x1b[0m                 |\n");
	printf("|                                              |\n");
	printf("|               Client Version                 |\n");
	printf("|                                              |\n");
	printf("================================================\n");
	socket_setup(av[1], ft_atoi(av[2]));
	return (0);
}
