/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:21:26 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/26 14:00:56 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <string.h>

int	ft_exec_cmd(t_mishell mish, t_files files)
{
	int	b;

	b = check_if_cmd_built(mish.cmds[files.pos_cmd]);
	if (mish.cmds[files.pos_cmd].path == NULL && b == 0)
	{
		printf("Command '%s' not found\n", mish.cmds[files.pos_cmd].c[0]);
		exit (1);
		//ft_exit();
	}
	else if (check_built_fork(mish.cmds[files.pos_cmd].c, &files) == 0)
	{
		if (execve(mish.cmds[files.pos_cmd].path, mish.cmds[files.pos_cmd].c, files.tab_var_env) == -1)
		{
			printf("minishell: %s: %s\n", mish.cmds[files.pos_cmd].c[0], strerror(errno));
			exit (1);
			//ft_exit();
		}
	}
	return (0);
}
