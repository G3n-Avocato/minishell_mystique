/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:41:09 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/09 16:05:39 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cat(char const *s1, char const *s2, char *s3)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
	{
		s3[i] = s2[y];
		i++;
		y++;
	}
	s3[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		size_s3;

	if (!s1)
		return (NULL);
	size_s3 = ft_strlen((char *) s1) + ft_strlen((char *) s2);
	s3 = malloc(sizeof(char) * (size_s3 + 1));
	if (!s3)
		return (NULL);
	ft_cat(s1, s2, s3);
	return (s3);
}
