/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:46:47 by lamasson          #+#    #+#             */
/*   Updated: 2022/11/22 16:10:58 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char *str)
{
	int		y;
	int		i;
	char	*line;

	y = 0;
	i = ft_check(str);
	if (i == 0)
		i = ft_strlen(str);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (y < i)
	{
		line[y] = str[y];
		y++;
	}
	line[y] = '\0';
	return (line);
}

static char	*ft_get_tmp(char *tmp)
{
	char	*new_tmp;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = ft_check(tmp);
	j = ft_strlen(tmp);
	if (i == 0 || i == j)
	{
		free(tmp);
		return (NULL);
	}
	new_tmp = malloc(sizeof(char) * ((j - i) + 1));
	if (!new_tmp)
		return (NULL);
	while (tmp[i] != '\0')
	{
		new_tmp[k] = tmp[i];
		k++;
		i++;
	}
	new_tmp[k] = '\0';
	free(tmp);
	return (new_tmp);
}

static void	ft_join(char *tmp, char *buf, char *s3)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (tmp && tmp[i] != '\0')
	{
		s3[i] = tmp[i];
		i++;
	}
	while (buf && buf[y] != '\0')
	{
		s3[i] = buf[y];
		i++;
		y++;
	}
	s3[i] = '\0';
}

static char	*ft_strjoin_gnl(char *tmp, char *buf)
{
	char	*s3;
	int		size_s3;

	size_s3 = ft_strlen(tmp) + ft_strlen(buf);
	s3 = malloc(sizeof(char) * (size_s3 + 1));
	if (!s3)
		return (NULL);
	ft_join(tmp, buf, s3);
	if (tmp)
		free(tmp);
	return (s3);
}

char	*get_next_line(int fd)
{
	static char	*tmp = NULL;
	char		*line;
	char		*buf;
	int			i;

	i = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (i != 0 && ft_check(tmp) == 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == 0 || i == -1)
			break ;
		buf[i] = '\0';
		tmp = ft_strjoin_gnl(tmp, buf);
	}
	free(buf);
	if (!tmp)
		return (NULL);
	line = ft_get_line(tmp);
	tmp = ft_get_tmp(tmp);
	return (line);
}
