/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_var_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:00:23 by lamasson          #+#    #+#             */
/*   Updated: 2023/06/01 17:58:55 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_dollar(char *str) //if 0 good if 1 not good 
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (-1);
}

char	*rec_name_var_env(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] != '=')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	name = ft_substr(str, 0, i);
	if (!name)
		exit (1);
	return (name);
}

char	*ft_wheel_tab_var_env(t_files files, char *name, int len_n)
{
	int		i;
	int		len_tmp;
	int		len_val;
	char	*tmp;

	i = 0;
	while (files.tab_var_env[i] != NULL)
	{
		tmp = rec_name_var_env(files.tab_var_env[i]);
		len_tmp = ft_strlen(tmp);
		if (ft_strncmp(tmp, name, len_tmp) == 0 && len_tmp == len_n)
		{
			free(tmp);
			len_val = ft_strlen(files.tab_var_env[i]);
			tmp = ft_substr(files.tab_var_env[i], len_tmp + 1, len_val - (len_tmp + 1));
			return (tmp);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*ft_rec_val_env(t_files files, char *str)
{
	int	len;
	int	pos;
	int	end

	len = ft_strlen(str);
	pos = ft_check_dollar(str);
	end = 
	while ()






}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	int	*pos = 0;
	int	i = 0;
	t_files	files;
	char *str;
	char *new;

	str = "$PWD.SDSS"; //$USER$USER $USERldl
	ft_init_tab_env(env, &files);

	pos = ft_check_dollar



}
