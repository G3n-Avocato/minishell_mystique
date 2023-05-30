/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:21:18 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/09 19:04:42 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;
	size_t	size_src;

	size_src = ft_strlen(src);
	if (!dst && !size)
		return (size_src);
	size_dst = ft_strlen(dst);
	i = 0;
	if (size_dst >= size)
		return (size_src + size);
	while (src[i] != '\0' && size - 1 > i + size_dst)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}
