/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:47:34 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/09 15:48:09 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_set(char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	y;

	if (!s1)
		return (NULL);
	i = 0;
	y = ft_strlen(s1);
	while (ft_char_set(s1[i], set) == 1)
		i++;
	while (ft_char_set(s1[y - 1], set) == 1)
		y--;
	s2 = ft_substr(s1, i, (y - i));
	if (!s2)
		return (NULL);
	return (s2);
}
