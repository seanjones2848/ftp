/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:46:34 by sjones            #+#    #+#             */
/*   Updated: 2017/01/20 15:18:41 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**ret;
	char	*t;
	int		i;

	if (s != NULL)
	{
		i = 0;
		t = (char*)s;
		if (!(ret = (char**)malloc(sizeof(char*) * ft_wordcnt(s, c) + 1)))
			return (NULL);
		while (*t && (i < ft_wordcnt(s, c)))
		{
			while (*t == c)
				t++;
			if (!(ret[i++] = ft_strndup(t, ft_wordlen(t, c))))
				return (NULL);
			while (*t != c)
				t++;
		}
		ret[i] = NULL;
		return (ret);
	}
	return (NULL);
}
