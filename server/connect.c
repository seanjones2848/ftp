/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:59:53 by sjones            #+#    #+#             */
/*   Updated: 2018/04/02 22:11:57 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	connect_out(t_srv *s)
{
	while (1)
	{
		ft_bzero(s->buffer, BUFF_MAX);
		if (!(read(s->c_fd, s->buffer, BUFF_MAX - 1)))
		{
			printf("Error reading on socket\n");
			continue;
		}
		if (ft_strcmp((const char *)&s->buffer, "QUIT") == 0)
		{
			printf("Client disconnected from  socket %d\n", s->c_fd);
			close(s->c_fd);
			exit(1);
		}
		else
			process_client(s);
	}
}

void	connect_hub(t_srv *s)
{
	int		c_pid;

	c_pid = 0;
	while (1)
	{
		if (!(s->c_fd = accept(s->sock, (struct sockaddr*)&s->c_addr, (socklen_t *)sizeof(struct sockaddr_in))))
		{
			printf("Error accepting client\n");
			break;
		}
		else if (s->c_fd < 0)
			continue;
		else {
			printf("New client from %s:%d on sd %d\n", inet_ntoa(s->c_addr.sin_addr), ntohs(s->c_addr.sin_port), s->c_fd);
			if ((c_pid = fork()) == -1)
			{
				printf("Error forking proccess for new client\n");
				continue;
			}
			if (c_pid == 0)
				connect_out(s);
		}
	}
}
