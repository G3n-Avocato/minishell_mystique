/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:45:48 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/26 13:16:30 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//recupere entrer et renvoie sortit sous condition ? pipe et redirection ?
//fct en cours parsing built - retour erreur dans parsing ou ici ?

int	check_built_no_fork(char **c, t_files *files)
{
	size_t	len;

	len = ft_strlen(c[0]);
	if (ft_strncmp(c[0], "exit", len) == 0 && len == ft_strlen("exit"))
	{
		//ft_exit(); //no option
		exit (1);
	}
	else if (ft_strncmp(c[0], "cd", len) == 0 && len == ft_strlen("cd"))
		ft_cd(c, files); //with relative or absolute path
	else if (ft_strncmp(c[0], "export", len) == 0 && len == ft_strlen("export"))
		ft_export(c, files); //no option
	else if (ft_strncmp(c[0], "unset", len) == 0 && len == ft_strlen("unset"))
		ft_unset(c, files); //no option
	else
		return (0);
	return (1);
}

int	check_built_fork(char **c, t_files *files)
{
	size_t	len;
	
	len = ft_strlen(c[0]);
	if (ft_strncmp(c[0], "pwd", len) == 0 && len == ft_strlen("pwd"))
		ft_pwd(c); //no option
	else if (ft_strncmp(c[0], "env", len) == 0 && len == ft_strlen("env"))
		ft_env(*files); //no option no args
	else if (ft_strncmp(c[0], "echo", len) == 0 && len == ft_strlen("echo"))
		ft_echo(c); //no option no args
	else 
		return (0);
	return (1);
}

int	check_if_cmd_built(t_cmd cmds)
{
	size_t	len;
	char *c;

	c = cmds.c[0];
	len = ft_strlen(c);
	if (ft_strncmp(c, "cd", len) == 0 && len == 2)
		return (1);
	else if (ft_strncmp(c, "exit", len) == 0 && len == 4)
		return (1);
	else if (ft_strncmp(c, "export", len) == 0 && len == 6)
		return (1);
	else if (ft_strncmp(c, "unset", len) == 0 && len == 5)
		return (1);
	else if (ft_strncmp(c, "pwd", len) == 0 && len == 3)
		return (1);
	else if (ft_strncmp(c, "env", len) == 0 && len == 3)
		return (1);
	else if (ft_strncmp(c, "echo", len) == 0 && len == 4)
		return (1);
	else
		return (0);
}
