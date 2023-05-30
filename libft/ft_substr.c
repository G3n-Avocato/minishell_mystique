/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:19:04 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/09 18:31:41 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		t = ft_strdup("");
		return (t);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	t = malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	while (i < len)
	{
		t[i] = s[start];
		i++;
		start ++;
	}
	t[i] = '\0';
	return (t);
}
