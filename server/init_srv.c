/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_srv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:19:20 by sjones            #+#    #+#             */
/*   Updated: 2018/04/02 22:01:37 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	create_socket(int port, t_srv *s)
{
	struct protoent	*tcp_pro;

	if ((tcp_pro = getprotobyname("tcp")) == 0 ||
		(s->sock = socket(PF_INET, SOCK_STREAM, tcp_pro->p_proto)) == -1)
	{
		printf("Error creating master socket\n");
		exit(-1);
	}
	s->s_addr.sin_family = AF_INET;
	s->s_addr.sin_port = htons(port);
	s->s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (setsockopt(s->sock, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 },
		sizeof(int)) < 0)
	{
		printf("Error setting master socket options\n");
		exit(-1);
	}
	if (bind(s->sock, (const struct sockaddr *)&s->s_addr, sizeof(s->s_addr)) < 0)
	{
		printf("Error binding socket\n");
		exit(-1);
	}
}

void	init_srv(int port, t_srv *s)
{
	s->port = port;
	s->sock = 0;
	ft_bzero((char *) &s->s_addr, sizeof(s->s_addr));
	ft_bzero((char *) &s->c_addr, sizeof(s->c_addr));
	create_socket(s->port, s);
}
