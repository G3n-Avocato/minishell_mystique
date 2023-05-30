/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:32:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/26 17:03:01 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_cat_path(char *s1, char *s2, char *s3)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	if (s1[i - 1] != '/')
	{
		s3[i] = '/';
		i++;
	}
	while (s2[y] != '\0')
	{
		s3[i] = s2[y];
		i++;
		y++;
	}
	s3[i] = '\0';
}

char *ft_strjoin_path(char *path, char *cmd)
{
	char	*s3;
	int		len;
	int		i;

	if (!path)
		return (NULL);
	i = ft_strlen(path);
	if (path[i - 1] != '/')
		len = i + ft_strlen(cmd) + 1;
	else
		len = i + ft_strlen(cmd);
	s3 = malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (NULL);
	ft_cat_path(path, cmd, s3);
	return (s3);
}
