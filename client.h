/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 03:26:55 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/27 03:28:14 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <stdio.h>
# include <sys/socket.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <string.h>
# include "libft/libft.h"
# include <arpa/inet.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <net/if.h>

int		do_put(int sock, char *str);
int		do_get(int sock, char *str);
void	do_cd(int sock, char *str);
void	do_ls(int sock, char *arg);
void	do_lls();
void	do_lcd(char *str);
void	do_lpwd();
void	do_pwd(int sock);
void	do_quit(int sock);
void	do_mkdir(int sock, char *dirname);
void	do_rmdir(int sock, char *dirname);
void	do_unlink(int sock, char *dirname);
int		send_file(int sock, int size, int fd);
#endif
