/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:27:54 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/08 16:09:09 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb > 65535)
		return (NULL);
	s = malloc(nmemb * size);
	if (s == 0)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}	
