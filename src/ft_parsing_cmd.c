/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:52:20 by gbertet           #+#    #+#             */
/*   Updated: 2023/05/25 15:29:17 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int empty_str(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (1);
	while (ft_iswhitespace(s[i]))
		i++;
	if (!s[i])
		return (1);
	return (0);
}

int	check_pipe(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '|' && !ft_betweenquotes(s, i))
		{
			if (s[i + 1] == ' ')
				i++;
			if (s[i + 1] == '|' || !s[i + 1])
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_here_doc(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '<' && s[i + 1] == '<' && !ft_betweenquotes(s, i))
		{
			if (s[i + 2] == '<' || !s[i + 2])
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_quotes(char *s)
{
	int i;
	int sq;
	int	dq;

	i = -1;
	sq = 0;
	dq = 0;
	while (s[++i])
	{
		if (s[i] == '\"')
			dq++;
		else if (s[i] == '\'')
			sq++;
	}
	if (dq % 2 == 1)
	{
		printf("Synthax error near unexpected token '\"'.\n");
		return (0);
	}
	else if (sq % 2 == 1)
	{
		printf("Synthax error near unexpected token '\''.\n");
		return (0);
	}
	return (1);
}

int synthax_check(char *s)
{
	if (!check_pipe(s) || s[0] == '|')
	{
		free(s);
		printf("Synthax error near unexpected token '|'.\n");
		return (0);
	}
	if (!check_here_doc(s) || s[ft_strlen(s) - 1] == '>')
	{
		free(s);
		printf("Synthax error near unexpected token '<'.\n");
		return (0);
	}
	if (!check_quotes(s))
	{
		free(s);
		return (0);
	}
	return (1);
}