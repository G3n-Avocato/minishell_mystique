/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:59:02 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/31 19:07:04 by lamasson         ###   ########.fr       */
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
	if (!name)
		exit (1);
	if (ft_strncmp(name, "PWD", 3) == 0 || ft_strncmp(name, "OLDPWD", 6) == 0 \
		|| ft_strncmp(name, "HOME", 4) == 0 || ft_strncmp(name, "USER", 4) == 0)
	{
		free(name);
		return (NULL);
	}
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
int	ft_parse_name(char *str)
{
	int	i;

	i = 1;
	if (ft_isalpha(str[0]) != 1)
		return (1);
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		if (ft_isalnum(str[i]) != 1 && str[i] != '_' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_export(char **c, t_files *files)
{
	char	*name;
	int		i;

	i = 0;
	if (!c[1])
	{
		ft_export_no_arg(*files);
		return (0);
	}
	while (c[++i])
	{
		if (ft_parse_name(c[i]) == 1) 
			continue ;
		name = rec_var_env(c[i]);
		if (!name)  //si NULL tentative de modifier une var_env essentiel au fct du program
			return (1);
		if (getenv(name) != NULL)
			switch_env(files, name, c[i]);
		else
		{
			free(name);
			ft_realloc_tab_env(files, c[i]); 
		}
	}
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
