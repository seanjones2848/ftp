/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:54:31 by sjones            #+#    #+#             */
/*   Updated: 2018/04/02 17:24:09 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ftp(int port)
{
	init();
	listen();
}

void	ftpd(int port)
{
	daemonize();
	ftp(port);
}

void	sftp(int port)
{
	secure();
	ftp(port);
}

void	sftpd(int port)
{
	daemonize();
	sftp(port);
}
