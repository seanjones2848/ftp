/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 14:29:48 by sjones            #+#    #+#             */
/*   Updated: 2018/04/02 21:47:41 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int main(int ac, char **av)
{
	t_srv	s;

	if (ac != 2)
	{
		printf("Usage: ./server port\n");
		return (-1);
	}
	init_srv(ft_atoi(av[1]), &s);
	if (listen(s.sock, 4) == 0)
		printf("Waiting for connection\n");
	else
		printf("Error, binding port %d might be in use\n", s.port);
	connect_hub(&s);
	close(s.c_fd);
	close(s.sock);
	return (0);
}
