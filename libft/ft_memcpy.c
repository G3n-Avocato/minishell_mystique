/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:55:32 by lamasson          #+#    #+#             */
/*   Updated: 2022/09/28 22:34:06 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*temp2;

	if (!dest && !src)
		return (dest);
	temp = (char *) src;
	temp2 = (char *) dest;
	while (n != 0)
	{
		n--;
		temp2[n] = temp[n];
	}
	return (dest);
}
