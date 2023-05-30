/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:14:31 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/09 18:29:42 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*t;
	unsigned int	t_size;
	unsigned int	i;

	if (!s)
		return (NULL);
	t_size = ft_strlen(s);
	t = malloc(sizeof(char) * (t_size + 1));
	if (!t)
		return (NULL);
	i = 0;
	while (i < t_size)
	{
		t[i] = f(i, s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
