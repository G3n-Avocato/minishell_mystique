/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:53:32 by gbertet           #+#    #+#             */
/*   Updated: 2023/05/26 20:12:41 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*	Return 1 si le char s[pos] est entre des
	doubles/simples quotes, sinon return 0.	*/
int ft_betweenquotes(char *s, int pos)
{
	int		i;
	int		quote;
	int		len;
	char	c;

	i = -1;
	quote = 0;
	c = '\0';
	if (!s[pos])
		return (0);
	len = ft_strlen(s);
	if (len <= pos)
		return (0);
	while (s[++i])
	{
		if (i == pos)
			return (quote);
		else if (!quote && (s[i] == '\'' || s[i] == '\"'))
		{
			quote = 1;
			c = s[i];
		}
		else if (quote && s[i] == c)
			quote = 0;
	}
	return (0);
}

int	ft_strstrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_str_nb_redir(char **s, char *redir, int end_char)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (!ft_strncmp(s[i], redir, ft_strlen(redir) + end_char))
			n++;
		i++;
	}
	return (n);
}

int ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
