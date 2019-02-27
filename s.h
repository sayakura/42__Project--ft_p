/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 03:16:19 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/27 03:16:20 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_H
# define S_H

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

# define IPV6 1

void	s_do_put(int sock, char *filename);
void	s_do_get(int sock, char *filename);
void	s_do_cd(int sock, char *path);
void	s_do_ls(int sock, char *arg);
void	s_do_pwd(int sock);
void	s_do_mkdir(int sock, char *dirname);
void	s_do_rmdir(int sock, char *dirname);
void	s_do_unlink(int sock, char *filename);
int		handle_op(int sock);
#endif
