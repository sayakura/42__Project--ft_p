/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:34:15 by qpeng             #+#    #+#             */
/*   Updated: 2019/02/26 12:34:17 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H

# define COMMON_H
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define BLACK   "\033[0;90m"
# define RESET   "\x1b[0m"
# define GO_UP   "\033[F"

int		receive_file(int client_socket, int file_size, int received_file_fd);
int		send_file(int server_sock, int file_size, int fd);
char	get_char();
char	*get_input();
int		ip_version(const char *src);

#endif
