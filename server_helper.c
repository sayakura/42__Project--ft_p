/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 02:31:05 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/27 02:31:09 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s.h"

extern char *g_home_dir;

int		handle_op(int sock)
{
	char buf[100];

	if (recv(sock, buf, 100, 0) == 0)
		return (0);
	if ((ft_strncmp(buf, "ls", 2)) == 0 &&
		(buf[2] == '\0' || buf[2] == ' '))
		s_do_ls(sock, buf + 3);
	else if ((ft_strncmp(buf, "cd ", 3)) == 0)
		s_do_cd(sock, buf + 3);
	else if ((ft_strncmp(buf, "get ", 4)) == 0)
		s_do_get(sock, buf + 4);
	else if ((ft_strncmp(buf, "put ", 4)) == 0)
		s_do_put(sock, buf + 4);
	else if ((ft_strncmp(buf, "pwd", 3)) == 0)
		s_do_pwd(sock);
	else if ((ft_strncmp(buf, "unlink ", 6)) == 0)
		s_do_unlink(sock, buf + 7);
	else if ((ft_strncmp(buf, "rmdir ", 6)) == 0)
		s_do_rmdir(sock, buf + 6);
	else if ((ft_strncmp(buf, "mkdir ", 6)) == 0)
		s_do_mkdir(sock, buf + 6);
	else
		return (0);
	return (1);
}

void	s_do_pwd(int sock)
{
	char	*path;
	int		len;

	path = getcwd(NULL, 200);
	len = ft_strlen(path + ft_strlen(g_home_dir));
	if (len == 0)
	{
		len = 2;
		send(sock, &len, sizeof(int), 0);
		send(sock, "/\0", len, 0);
	}
	else
	{
		send(sock, &len, sizeof(int), 0);
		send(sock, path + ft_strlen(g_home_dir), len, 0);
	}
	free(path);
}

void	s_do_mkdir(int sock, char *dirname)
{
	int	status;

	status = (mkdir(dirname, 0766) == -1) ? 0 : 1;
	send(sock, &status, sizeof(int), 0);
}

void	s_do_rmdir(int sock, char *dirname)
{
	int status;

	status = (rmdir(dirname) == -1) ? 0 : 1;
	send(sock, &status, sizeof(int), 0);
}

void	s_do_unlink(int sock, char *filename)
{
	int status;

	status = (unlink(filename) == -1) ? 0 : 1;
	send(sock, &status, sizeof(int), 0);
}
