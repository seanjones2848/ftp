# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 13:04:32 by sjones            #+#    #+#              #
#    Updated: 2018/04/02 17:24:03 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SER = server

CLI = client

client:

serveur:

all: client serveur
	make -C libft


clean:
	rm -rf obj

fclean: clean
	rm server client

re: fclean all

.phony client serveur all clean fclean re
