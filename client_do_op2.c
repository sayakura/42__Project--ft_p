/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_do_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 03:12:25 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/27 03:12:28 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "common.h"

void	do_lls(void)
{
	if (fork() == 0)
	{
		execl("/bin/ls", "ls", NULL);
		exit(0);
	}
	wait(NULL);
}

void	do_lpwd(void)
{
	char	*path;

	path = getcwd(NULL, 200);
	printf("%s» %s%s\n", MAGENTA, path, RESET);
	free(path);
}

void	do_mkdir(int sock, char *dirname)
{
	int		size;
	char	buf[100];

	ft_bzero(buf, 100);
	ft_strcpy(buf, "mkdir ");
	ft_strcat(buf, dirname);
	send(sock, buf, 100, 0);
	recv(sock, &size, sizeof(int), 0);
	if (!size)
		printf("%s» [ERROR] mkdir failed.%s\n", RED, RESET);
}

void	do_rmdir(int sock, char *dirname)
{
	int		size;
	char	buf[100];

	ft_bzero(buf, 100);
	ft_strcpy(buf, "rmdir ");
	ft_strcat(buf, dirname);
	send(sock, buf, 100, 0);
	recv(sock, &size, sizeof(int), 0);
	if (!size)
		printf("%s» [ERROR] rmdir failed.%s\n", RED, RESET);
}

void	do_unlink(int sock, char *filename)
{
	int		size;
	char	buf[100];

	ft_bzero(buf, 100);
	ft_strcpy(buf, "unlink ");
	ft_strcat(buf, filename);
	send(sock, buf, 100, 0);
	recv(sock, &size, sizeof(int), 0);
	if (!size)
		printf("%s» [ERROR] unlink failed.%s\n", RED, RESET);
}
