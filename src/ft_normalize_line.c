/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:59:08 by gbertet           #+#    #+#             */
/*   Updated: 2023/05/26 20:03:47 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_less_whitespace(char *s)
{
	int		i;
	int		tmp;
	char	*res;

	i = 0;
	res = ft_strdup(s);
	while (res[i])
	{
		if (ft_iswhitespace(res[i]) && ft_iswhitespace(res[i + 1]) && !ft_betweenquotes(res, i))
		{
			tmp = i;
			while (res[tmp])
			{
				res[tmp] = res[tmp + 1];
                tmp++;
			}
			res[i] = ' ';
		}
		else
			i++;
	}
	return (res);
}

char	*add_char_right(char *s, int pos)
{
	int	i;

	i = ft_strlen(s);
	if (!i)
		return (NULL);
	s = ft_realloc(s, i, i + 1);
	s[i + 1] = '\0';
	while (i != pos)
	{
		s[i] = s[i - 1];
		i--;
	}
	s[pos] = ' ';
	return (s);
}

char	*format_str_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_betweenquotes(s, i))
		{
			if (s[i] != '|' && s[i] != '<' && s[i] != '>' && s[i] != ' ')
			{
				if ((s[i + 1] == '|' || s[i + 1] == '<' || s[i + 1] == '>') && !ft_betweenquotes(s, i + 1))
					s = add_char_right(s, i + 1);
			}
			else if (s[i] == '|' && s[i + 1] != ' ')
				s = add_char_right(s, i + 1);
			else if (s[i] == '<' || s[i] == '>')
			{
				if (s[i + 1] != '<' && s[i + 1] != '>' && s[i + 1] != ' ' && s[i + 1])
					s = add_char_right(s, i + 1);
			}
		}
		i++;
	}
	return (s);
}

char	*normalize_str(char *s)
{
	int	i;
	int	j;
	char	*res;
	char	*tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[i]))
		i++;
	while (j > 0)
	{
		if (!ft_iswhitespace(s[j]))
			break;
		j--;
	}
	tmp = ft_substr(s, i, j - i + 1);
	res = ft_less_whitespace(tmp);
	res = format_str_spaces(res);
	free(tmp);
	return (res);
}
