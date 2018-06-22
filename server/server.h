/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:28:18 by sjones            #+#    #+#             */
/*   Updated: 2018/04/02 21:23:43 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/libft.h"
# include <arpa/inet.h>
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <netdb.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define BUFF_MAX 4096

typedef struct			s_srv
{
	int					port;
	int					sock;
	struct sockaddr_in	s_addr;
	struct sockaddr_in	c_addr;
	int					c_fd;
	int					nfds;
	fd_set				*read_fds;
	fd_set				*write_fds;
	fd_set				*error_fds;
	char				buffer[BUFF_MAX];
}						t_srv;

/*
**	FTP server prototypes
**	ftp.c
*/

void	ftp(int port);
void	ftpd(int port);
void	sftp(int port);
void	sftpd(int port);

/*
**	Specialized wrappers
**	daemon.c && ssl.c
*/

void	daemonize(void);
void	secure(void);

/*
** FTP functions
*/

void	init_srv(int port, t_srv *s);
void	connect_hub(t_srv *s);
void	process_client(t_srv *s);

#endif
