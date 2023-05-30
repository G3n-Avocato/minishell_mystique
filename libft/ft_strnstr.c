/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:34:34 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/11 21:51:46 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0' || big == little)
		return ((char *) big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while (big[i] == little[j])
			{
				if (little[j + 1] == '\0' && i < len)
					return ((char *) big + (i - j));
				i++;
				j++;
			}
		}
		else
			j = 0;
		i++;
	}
	return (0);
}
