/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:54:15 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/09 15:46:05 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*t;
	size_t	i;

	t = (char *) s;
	i = 0;
	while (i != n)
	{
		if (*t == (char) c)
			return (t);
		else
		{
			t++;
			i++;
		}
	}
	return (NULL);
}
