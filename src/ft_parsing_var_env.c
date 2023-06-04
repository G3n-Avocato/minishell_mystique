/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_var_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:00:23 by lamasson          #+#    #+#             */
/*   Updated: 2023/06/04 17:31:33 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_dollar(char *str, int i) //if 0 good if 1 not good 
{
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (-1);
}
//////////////////////////////////////
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

int	ft_wheel_tab_var_env(t_files files, t_var_env *data, int j)
{
	int		i;
	int		len_tmp;
	char	*tmp;

	i = 0;
	while (files.tab_var_env[i] != NULL)
	{
		tmp = rec_name_var_env(files.tab_var_env[i]);
		len_tmp = ft_strlen(tmp);
		if (ft_strncmp(tmp, data->val[j].name, len_tmp) == 0 && len_tmp == data->val[j].len_n)
		{
			free(tmp);
			data->val[j].new_len = ft_strlen(files.tab_var_env[i]);
			data->val[j].new_str = ft_substr(files.tab_var_env[i], len_tmp + 1, data->val[j].new_len - (len_tmp + 1));
			return (0);
		}
		free(tmp);
		i++;
	}
	data->val[j].new_len = 0;
	data->val[j].new_str = "";
	return (-1);
}

void	ft_init_new_str(t_files files, t_var_env *data)
{
	int	i;
	char	*finish;

	i = 0;
	while (i < data->nb_dol)
	{
		ft_wheel_tab_var_env(files, data, i);
		i++; 
	}
	data->val[i].new_str = NULL;
	finish = ft_join_all_str(data);
	printf("%s\n", finish);
	free(finish);
}

int	ft_check_end_name(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			break ;
		if (str[i] >= 32 && str[i] <= 47)
			break ;
		if (str[i] >= 58 && str[i] <= 64)
			break ;
		if (str[i] >= 91 && str[i] <= 96)
			break ;
		if (str[i] >= 123 && str[i] <= 126)
			break ;
		i++;
	}
	return (i);
}

void	ft_parse_struct_var_env(char *str, t_var_env *data)
{
	int			i;
	
	i = 0;
	while (str[data->len] != '\0')
	{
		if (str[data->len] == '$')
			data->nb_dol++;
		data->len++;
	}
	data->val = malloc(sizeof(t_new_str) * (data->nb_dol + 1));
	data->val[data->nb_dol].name = NULL;
	while (i < data->nb_dol)
	{
		data->val[i].i_dol = i;
		data->val[i].start = ft_check_dollar(str, data->pos_s);
		data->pos_s = data->val[i].start;
		data->val[i].len_n = ft_check_end_name(str, data->pos_s);
		data->val[i].len_n = data->val[i].len_n - data->val[i].start;
		data->val[i].name = ft_substr(str, data->val[i].start, data->val[i].len_n);
		if (!data->val[i].name)
			exit (1);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	char	*str;	

	str = "lol$PWD.SDSS"; // = lamasson.SDSS $USER$USER = lamassonlamasson $USERldl = ""
	t_files	files;
	ft_init_tab_env(env, &files);
	
	t_var_env	data;

	data.str = str;
	data.len = 0;
	data.nb_dol = 0;
	data.pos_s = 0;
	if (ft_check_dollar(str, 0) == -1)
		return (1);
	ft_parse_struct_var_env(str, &data);
	ft_init_new_str(files, &data);

/*	int	i = 0;
	while (i < data.nb_dol)
	{
		printf("%s\n", data.val[i].new_str);
		i++;
	}*/
	ft_free_tab(files.tab_var_env);
	ft_free_data_var_env(&data, data.nb_dol);
	return (0);
}


void	ft_free_data_var_env(t_var_env *data, int i)
{
	while (i != 0)
	{
		free(data->val[i].name);
		free(data->val[i].new_str);
		i--;
	}
	free(data->val);
}
