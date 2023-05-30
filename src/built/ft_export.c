/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:59:02 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/23 19:42:18 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_realloc_tab_env(t_files *files, char *str) //envoyer addr & de files dans proto
{
	int		len;
	int		i;
	char	**buf_tab;

	i = 0;
	len = ft_tablen(files->tab_var_env);
	buf_tab = malloc(sizeof(char *) * (len + 2)); //new + NULL = 2
	while (files->tab_var_env[i] != NULL)
	{
		buf_tab[i] = ft_strdup(files->tab_var_env[i]);
		free(files->tab_var_env[i]);
		i++;
	}
	free(files->tab_var_env);
	buf_tab[i] = ft_strdup(str);
	buf_tab[i + 1] = NULL;
	files->tab_var_env = buf_tab;
}

/*recupere le NAME malloc de la var_env //fix */

char	*rec_var_env(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] != '=')
	{
		if (str[i] == '\0')
			break ;
		i++;
	}
	name = ft_substr(str, 0, i);
	return (name);
}

void	switch_env(t_files *files, char *name, char *str)
{
	int	i;

	i = 0;
	while (files->tab_var_env[i] != NULL)
	{
		if (ft_strncmp(files->tab_var_env[i], name, ft_strlen(name)) == 0)
		{
			free(files->tab_var_env[i]);
			files->tab_var_env[i] = ft_strdup(str);
			if (files->tab_var_env[i] == NULL)
			{
				ft_free_tab_env(files);
				free(name);
				exit (1);
			}
			break ;
		}
		i++;
	}
	free(name);
}

/* check syntax name de la var_env */
//refaire
int	ft_parse_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] == '_' && str[1] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	ft_export(char **c, t_files *files)//nom var off change struct ok
{
	char	*name;
	char	*arg;

	arg = c[2]; //test c[2] vrai c[1]
	if (!arg)
	{
		ft_export_no_arg(*files); //in bash, tab is sort in alpha order with "declare -x"
		return (0);
	}
	if (ft_parse_name(arg) == 1) //if 1 NAME not ok 
		return (0);
	name = rec_var_env(arg);
	if (name == NULL)
	{
		ft_free_tab_env(files);
		exit (1);
	}
	if (getenv(name) != NULL) //if name var_env exist, switch old_value by new_value
	{
		switch_env(files, name, arg);
		return (0);
	}
	free(name);
	ft_realloc_tab_env(files, arg); //if name doesn't exist, add new var_env 
	return (0);
}
/*
int	main(int argc, char **argv, char **env)
{
	t_files	files;
	int		i;
	(void) argc;

	ft_init_tab_env(env, &files);
//	i = 0;
//	while (files.tab_var_env[i] != NULL)
//	{
//		printf("%s\n", files.tab_var_env[i]);
//		i++;
//	}
	ft_export(argv, &files);
//	ft_export(NULL, &files);
//	ft_unset(argv[2], &files);
	i = 0;
	while (files.tab_var_env[i] != NULL)
	{
		printf("%s\n", files.tab_var_env[i]);
		i++;
	}
	printf ("\n\n");

	ft_env(files);
	ft_free_tab_env(&files);
	return (0);
}*/
