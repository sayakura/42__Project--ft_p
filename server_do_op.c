/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_do_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 02:36:25 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/27 02:36:27 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "common.h"

extern char	*g_home_dir;

void		s_do_put(int sock, char *filename)
{
	int		fd;
	int		size;
	int		status;

	printf("PUT request received.\n");
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0666)) == -1)
	{
		perror("open");
		return ;
	}
	recv(sock, &size, sizeof(int), 0);
	status = receive_file(sock, size, fd);
	if (status)
		printf("Recived file: %s\n", filename);
	else
		printf("Failed to receive the file: %s\n", filename);
	send(sock, &status, sizeof(int), 0);
}

void		s_do_get(int sock, char *filename)
{
	char		*file;
	struct stat	sb;
	int			fd;

	if ((fd = open(filename, O_RDONLY)) != -1)
	{
		fstat(fd, &sb);
		if (S_ISREG(sb.st_mode))
		{
			file = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE\
				, MAP_PRIVATE, fd, 0);
			send(sock, &(sb.st_size), sizeof(int), 0);
			if (send_file(sock, sb.st_size, fd))
				printf("%sFile sent successfully.%s\n", GREEN, RESET);
			else
				printf("%sFile sending failed...%s\n", RED, RESET);
			munmap(file, sb.st_size);
			close(fd);
			return ;
		}
	}
	printf("%sFile is a dir or does not exists.%s\n", RED, RESET);
	close(fd);
	sb.st_size = -1;
	send(sock, &(sb.st_size), sizeof(int), 0);
}

int			s_do_cd(int sock, char *path)
{
	int		status;
	char	old_path[200];
	char	new_path[200];

	status = 0;
	if (path[0] == '\0')
	{
		chdir(g_home_dir);
		status = 1;
		return (send(sock, &status, sizeof(int), 0));
	}
	ft_bzero(old_path, 200);
	getcwd(old_path, 200);
	if ((chdir(path)) == -1)
		return (send(sock, &status, sizeof(int), 0));
	getcwd(new_path, 200);
	if (ft_strstr(new_path, g_home_dir) == NULL)
		chdir(old_path);
	else
		status = 1;
	return (send(sock, &status, sizeof(int), 0));
}

void		ls_to_file(int fd, char *arg)
{
	dup2(fd, 1);
	dup2(fd, 2);
	execl("/bin/ls", "ls", ft_strlen(arg) ? arg : NULL, NULL);
}

void		s_do_ls(int sock, char *arg)
{
	int			fd;
	char		*data;
	struct stat	sb;

	if ((fd = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		ft_errorexit("open gg");
	if (fork() == 0)
		ls_to_file(fd, arg);
	else
	{
		wait(NULL);
		close(fd);
		fd = open(".tmp", O_RDWR, 0666);
		if (fstat(fd, &sb) == -1)
			ft_errorexit("fstat gg");
		send(sock, &(sb.st_size), sizeof(int), 0);
		data = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE,\
			MAP_PRIVATE, fd, 0);
		send(sock, data, sb.st_size, 0);
		munmap(data, sb.st_size);
		close(fd);
		unlink(".tmp");
	}
}
