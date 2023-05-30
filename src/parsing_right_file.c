/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_right_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:54:57 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/26 17:10:31 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* check si fd_in accessible
 * erreur chmod */

int	ft_check_fdin(char *in)
{
	int	fd_in;

	if (in == NULL)
		return (1);
	fd_in = open(in, O_RDONLY);
	if (fd_in == -1)
	{
		printf("minishell: %s: %s\n", in, strerror(errno));
		return (1);
	}
	else
		close(fd_in);
	return (0);
}

/* check si fd_out accessible
 * erreur chmod et creation du
 * fichier de sortit si necessaire
 * et si possible*/

int	ft_check_fdout(char *out)
{
	int	fd_out;

	if (out == NULL)
		return (1);
	fd_out = open(out, O_RDWR);
	if (fd_out == -1)
	{
		fd_out = open(out, O_CREAT | O_TRUNC, 0644);
		if (fd_out == -1)
		{
			printf("minishell: %s: %s\n", out, strerror(errno));
			return (1);
		}
		else
			close(fd_out);
	}
	else
		close(fd_out);
	return (0);
}

int	ft_check_fd(char **fdins, char **fdouts, int nb_pipes)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	if (nb_pipes > 0)
	{	
		while (fdouts[i] && !err)
			err = ft_check_fdout(fdouts[i++]);
		i = 0;
		while (fdins[i] && !err)
			err = ft_check_fdin(fdins[i++]);
	}
	else
	{
		while (fdins[i] && !err)
			err = ft_check_fdin(fdins[i++]);
		i = 0;
		while (fdouts[i] && !err)
			err = ft_check_fdout(fdouts[i++]);
	}
	return (err);
}