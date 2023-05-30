/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:05:20 by lamasson          #+#    #+#             */
/*   Updated: 2022/09/28 22:35:28 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*temp2;
	size_t	i;

	if (!dest && !src)
		return (dest);
	temp = (char *) src;
	temp2 = (char *) dest;
	i = 0;
	while (n != i)
	{
		if (temp >= temp2)
		{
			temp2[i] = temp[i];
			i++;
		}
		else
		{
			n--;
			temp2[n] = temp[n];
		}
	}
	return (dest);
}
