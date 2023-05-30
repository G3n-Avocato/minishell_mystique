/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:12:52 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/09 15:05:45 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_tab_env(char **env, t_files *files) //envoyer addr,(&) de files dans proto
{
	int		len;
	int		i;

	i = 0;
	len = ft_tablen(env);
	files->tab_var_env = malloc(sizeof(char *) * (len + 1));
	while (env[i] != NULL)
	{
		files->tab_var_env[i] = ft_strdup(env[i]);
		i++;
	}
	files->tab_var_env[i] = NULL;
}

void	ft_free_tab_env(t_files *files)
{
	int	i;

	i = 0;
	while (files->tab_var_env[i] != NULL)
	{
		free(files->tab_var_env[i]);
		i++;
	}
	free(files->tab_var_env);
}

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}
