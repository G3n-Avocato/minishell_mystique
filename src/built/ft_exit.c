/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:54:31 by gbertet           #+#    #+#             */
/*   Updated: 2023/05/27 16:15:37 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_free_cmds(t_mishell *m)
{
	int	i;

	i = 0;
	free(m->full_cmd);
	while (m->cmds[i].c)
	{
		ft_free_str(m->cmds[i].c);
		free(m->cmds[i].path);
		i++;
	}
	free(m->cmds);
}

void	ft_free_files(t_files *files)
{
	ft_free_tab(files->tab_path);
	ft_free_tab(files->tab_var_env);
	if (files->fd_in)
		free(files->fd_in);
	if (files->fd_out)
		free(files->fd_out);
}

void    ft_exit(t_mishell *m)   
{
	if (m)
		ft_free_cmds(m);
	exit (1);
}
