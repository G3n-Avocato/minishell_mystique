/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:59:57 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/09 16:08:03 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	int		u;

	t = (char *) s;
	u = ft_strlen(t);
	while (*t != '\0')
		t++;
	while (u >= 0)
	{
		if (*t == (char) c)
			return (t);
		t--;
		u--;
	}
	return (NULL);
}	
