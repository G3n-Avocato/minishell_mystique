/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:42:56 by gbertet           #+#    #+#             */
/*   Updated: 2023/05/22 15:33:24 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_parse_tab_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

int	ft_env(t_files files)
{
	int	i;

	i = 0;
	if (!files.tab_var_env)
		return (1);
	while (files.tab_var_env[i])
	{
		if (ft_parse_tab_name(files.tab_var_env[i]) == 0)
			printf("%s\n", files.tab_var_env[i]);
		i++;
	}
	return (0);
}
