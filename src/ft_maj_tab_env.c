/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maj_tab_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:51:11 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/30 18:04:01 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	maj_tab_env_oldpwd(t_files *files)
{
	char	*buf;
	char	*name;

	buf = getenv("PWD");
	if (buf == NULL) //secu
		exit (1);
	buf = ft_strjoin("OLDPWD=", buf);
	if (buf == NULL) //secu
		exit (1);
	name = ft_strdup("OLDPWD");
	switch_env(files, name, buf);
	free(buf);
	return (0);
}

int	maj_tab_env_pwd(t_files *files)
{
	char	*pwd;
	char	*tmp;
	char	*name;

	pwd = malloc(sizeof(char *) * 1024);
	if (pwd == NULL) //secu
		exit (1);
	if (getcwd(pwd, 1024) == NULL)
	{
		free(pwd);
		exit (1);
	}
	tmp = ft_strjoin("PWD=", pwd);
	free(pwd);
	if (tmp == NULL) //secu
		exit (1);
	name = ft_strdup("PWD");
	switch_env(files, name, tmp);
	free(tmp);
	return (0);
}

/* main de test pour cd et maj_tab_env_pwd */
/*
int	main(int argc, char **argv, char **env)
{
	t_files	files;
	int		i;
	(void)argc;

	ft_init_tab_env(env, &files);
	i = 0;
	while (files.tab_var_env[i] != NULL)
	{
		if (ft_strncmp(files.tab_var_env[i], "PWD", 3) == 0 || ft_strncmp(files.tab_var_env[i], "OLDPWD", 6) == 0)
			printf("%s\n", files.tab_var_env[i]);
		i++;
	}
	i = 0;
	ft_cd(argv, &files);
	printf("\n\n\n");
	while (files.tab_var_env[i] != NULL)
	{
		if (ft_strncmp(files.tab_var_env[i], "PWD", 3) == 0 || ft_strncmp(files.tab_var_env[i], "OLDPWD", 6) == 0)
			printf("%s\n", files.tab_var_env[i]);
		i++;
	}
	ft_free_tab_env(&files);
	return (0);
}*/
