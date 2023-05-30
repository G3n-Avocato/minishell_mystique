/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_minishell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:35:28 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/27 18:46:40 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_size_tab(const char *s, char c)
{
	int	i;
	int	size_tab;

	i = 0;
	size_tab = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c && !ft_betweenquotes((char *)s, i))
			i++;
		if (s[i] && (s[i] != c || ft_betweenquotes((char *)s, i)))
			size_tab++;
		while (s[i] && (s[i] != c || ft_betweenquotes((char *)s, i)))
			i++;
	}
	return (size_tab);
}

static int	ft_getnext(const char *s, char c, int *j)
{
	int	nb;

	nb = 0;
	while (s[*j] && s[*j] == c && !ft_betweenquotes((char *)s, *j))
		(*j)++;
	while (s[*j] && (s[*j] != c || ft_betweenquotes((char *)s, *j)))
	{
		(*j)++;
		nb++;
	}
	return (nb);
}

char	**ft_split_minishell(char const *s, char c)
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