/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:08:33 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/30 17:59:56 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
//ft_readline en test

int	ft_cd(char **c, t_files *files)
{
	char	*path;
	
	path = c[1];
	if (path == NULL)
		return (1);
	if (chdir(path) != 0)
	{
		printf("minishell: %s: %s: %s\n", c[0], path, strerror(errno));
		return (1);
	}
	maj_tab_env_oldpwd(files);
	maj_tab_env_pwd(files);
	//ft_path_pos_prompt();
	return (0);
}
