/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:47:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/06/01 13:45:15 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>

int	open_fdin(t_files files)
{
	int	op;

	op = -1;
//	if (here_doc)//
//		op = .here_doc;// normalement .here_doc est deja dans fd_in a voir
	if (files.fd_in)
		op = open(files.fd_in, O_RDONLY);
	return (op);
}

int	open_fdout(t_files files)
{
	int	op;

	op = -1;
	if (files.out == 1)
		op = open(files.fd_out, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (files.out == 0)
		op = open(files.fd_out, O_RDWR | O_CREAT | O_TRUNC, 0644);	
	return (op);
}
/*
static void		ft_dup(int fd_in, int *fd, t_files files, t_mishell mish)
{
	if (files.fd_in == NULL && files.pos_cmd == 0)
	{
	//	dup2(fd[0], 0);
	//	close(fd[0]);
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
	}
	else
	{
		dup2(fd_in, 0);
		close(fd_in);
		close(fd[0]);
	}
	if (files.pos_cmd == mish.nb_cmds - 1 && files.fd_out != NULL)
	{
		close(fd[1]);
		fd[1] = ft_open_fd_out(files);
	}
	else 
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	//dup2(fd[1], 1);
	//close(fd[1]);

}*/

static void	ft_dup(int fd_in , int *fd, t_files files, t_mishell mish)
{
	int	out;

	if (files.fd_out != NULL && files.pos_cmd == mish.nb_cmds - 1)
	{
		close(fd[0]);
		out = open_fdout(files);
		dup2(out, 1);
		close(out);
	}
	else if (files.pos_cmd != mish.nb_cmds - 1)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
	}
	if (files.fd_in == NULL && files.pos_cmd == 0 && mish.nb_cmds > 1)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	else
	{
		close(fd[1]);
		dup2(fd_in, 0);
		close(fd_in);
	}
}

static int		ft_fork(t_mishell mish, t_files files, int fd_in, int *fd)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		perror("fork");
	if (pid == 0)
	{
		ft_dup(fd_in, fd, files, mish);
		ft_exec_cmd(mish, files);
	}
	if (files.pos_cmd == mish.nb_cmds - 1)
	{	
		close(fd[0]);
		if (files.fd_out != NULL)
			close(fd[1]);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

//gestion close here_doc voir si implementer
static int	ft_pipe(t_mishell mish, t_files files, int fd_in)
{
	int	fd[2];
	
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit (1);
	}
	ft_fork(mish, files, fd_in, fd);
	close(fd[1]);
	if (fd_in > 0)
		close(fd_in);
	return (fd[0]);
}

int	ft_call_pipex(t_mishell mish, t_files *files)
{
	int	fd_in;

	files->pos_cmd = 0;
	fd_in = open_fdin(*files);
	while (files->pos_cmd < mish.nb_cmds)
	{
		if (check_built_no_fork(mish.cmds[files->pos_cmd].c, files) == 0)
			fd_in = ft_pipe(mish, *files, fd_in);
		files->pos_cmd++;
	}
	if (fd_in > 0)
		close(fd_in);
	return (0);
}

/*
int	main(int argc, char **argv, char **env)
{
	t_mishell	mish;
	t_files	files;
	char	*str;
	char	**tab_str = NULL;
	int	j = 0;
	(void)argc;
	(void)argv;

	tab_str = malloc(3 * sizeof(char *));
	tab_str[0] = "export";
	tab_str[1] = "TEST";
	tab_str[2] = "saucii6se=2";
	tab_str[3] = "my-var=3";
	tab_str[4] = "PAGER=4";
	tab_str[5] = "var$=5";
	tab_str[6] =  "-l";
	tab_str[7] = ">";
	tab_str[8] = "test";
	tab_str[2] = NULL;
	str = "export TEST";
	//1SAUCISSE=1 saucii6se=2 my-var=3 PAGER=4 var$=5"; // NOM_VARIABLE=0 NOM_VARIABLE1=1 NOM_VARIABLE2=2 PAGER=SAUCISSE";

//parsing et init pour test //
	mish.full_cmd = normalize_str(str);
	get_cmds(&mish);
	ft_init_tab_env(env, &files);
	parsing_fd(tab_str, &files);

//nvx init necesssaire pour pipe // verif builtin here
	files.tab_path = ft_get_tab_path(files);
	while (j < mish.nb_cmds)
	{
		if (check_if_cmd_built(mish.cmds[j]) == 0)
			ft_init_path_cmd(&mish, files, j);
		else
			mish.cmds[j].path = NULL;
		j++;
	}

//pipex en test //
	
	ft_call_pipex(mish, &files);

	printf("\n\n");
	int	i = 0;
	while (files.tab_var_env[i])
	{
		//if (ft_strncmp(files.tab_var_env[i], "PWD", 3) == 0 || ft_strncmp(files.tab_var_env[i], "OLDPWD", 6) == 0)
		printf("%s\n\n", files.tab_var_env[i]);
		i++;
	}
	free(tab_str);	

	ft_free_files(&files);
	ft_free_cmds(&mish);
	return (0);
}*/
