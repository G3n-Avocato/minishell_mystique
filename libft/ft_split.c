/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:03:44 by lamasson          #+#    #+#             */
/*   Updated: 2022/10/09 18:25:32 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_tab(const char *s, char c)
{
	int	i;
	int	size_tab;

	i = 0;
	size_tab = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			size_tab++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (size_tab);
}

static int	ft_getnext(const char *s, char c, int *j)
{
	int	nb;

	nb = 0;
	while (s[*j] && s[*j] == c)
		(*j)++;
	while (s[*j] && s[*j] != c)
	{
		(*j)++;
		nb++;
	}
	return (nb);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_tab;
	int		nb_char;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nb_tab = ft_size_tab(s, c);
	tab = malloc(sizeof(char *) * (nb_tab + 1));
	if (!tab)
		return (NULL);
	tab[nb_tab] = NULL;
	i = 0;
	j = 0;
	while (i < nb_tab)
	{
		nb_char = ft_getnext(s, c, &j);
		tab[i] = ft_substr(s, j - nb_char, nb_char);
		i++;
	}
	return (tab);
}
