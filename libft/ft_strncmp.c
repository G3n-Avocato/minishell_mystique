/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:06:53 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/09 16:06:32 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	if (n == 0)
		return (0);
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while ((c1[i] != '\0' && c2[i] != '\0') && (c1[i] == c2[i] && i < n - 1))
		i++;
	return (c1[i] - c2[i]);
}
