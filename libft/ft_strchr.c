/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:10:45 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/08 15:52:42 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;

	t = (char *)s;
	while (*t != '\0')
	{
		if (*t == (char) c)
			return (t);
		else
			t++;
	}
	if (c == '\0')
		return (t);
	return (NULL);
}
