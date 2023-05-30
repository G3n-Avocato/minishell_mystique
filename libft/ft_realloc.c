/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:00:33 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/27 18:46:40 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t oldlen, size_t newlen)
{
	void	*newptr;

	if (!ptr)
		return (NULL);
	else if (oldlen >= newlen)
		return (ptr);
	else
	{
		newptr = malloc((newlen + 1) * sizeof(char));
		if (!newptr)
			return (NULL);
		ft_memcpy(newptr, ptr, oldlen);
		free(ptr);
	}
	return (newptr);
}
