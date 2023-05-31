/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:30:57 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/31 15:29:42 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h> //fork, wait, waitpid, wait3, wait4, open
# include <sys/wait.h> //wait
# include <fcntl.h> //access, open, unlink
# include <stdio.h> //printf
# include <stdlib.h> //malloc, free, getenv, exit
# include <unistd.h> //write, read, pipe, dup, dup2, execve, getcwd, chdir
# include <readline/readline.h> //readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include <readline/history.h>
# include <signal.h> //signal, sigaction, sigemptyset, sigaddset, kill
# include <errno.h> //strerror, perror
# include <sys/stat.h> //stat, lstat, fstat
# include <dirent.h> //opendir, readdir, closedir 
# include <sys/time.h> //?
# include <termios.h> //tcsetattr, tcgetattr, isatty, ttyname, ttyslot, ioctl
# include "../libft/libft.h"

typedef struct s_mishell
{
	struct s_cmd	*cmds;		//tableau de structure des commandes
	char			**av;		//tab argv du main
	char			*full_cmd;	//ligne de cmd du terminal
	char			path[1024];
	int				nb_cmds;	//nombre de commande dans la ligne
	int				type;
	int				*here_doc;
	char			**env;		//variable d'environnements du main 
}               t_mishell;

typedef struct	s_cmd			//tableau de struct
{
	char	**c;				//tableau cmd avc opt et arg pour chaque
	char	*path;				//path correspondant a la cmd ou NULL si builtin 
	int		here_doc;
}				t_cmd;

typedef struct s_files{
	char	*fd_in;			//string malloc de fd_in "test.c" if NULL no in
	char	*fd_out;		//string malloc de fd_out "test/test1.c" if NULL no out
	int		out;			// -1 = no fichier out / 0 redirection simple / 1 redirection append mode
	int		nb_pipe;		//defini ordre de verif (defini manuellement)(a revoir)(nb_cmds - 1 = nb_pipe)
	int		err;
	char	**tab_var_env;	//notre tableau de variables d'environnements
	char	**tab_path;		//PATH val split, tableau de tous les paths ':'
	int		pos_cmd;		//position dans le tab des cmds pendant son execution
}t_files;


//		MAIN.C					//
void	get_cmds(t_mishell *m);

//		FT_ENV.C				//
int		ft_env(t_files files);

//		FT_EXPORT.C				//
int		ft_export(char **c, t_files *files);
void	switch_env(t_files *files, char *name, char *str);
char	*rec_var_env(char *str);
int		ft_parse_name(char *str);

//		FT_EXPORT_UTILS.C		//
int		ft_export_no_arg(t_files files);
void	ft_free_n_tab(char **tab, int n);

//		FT_UNSET.C				//
int		ft_unset(char **c, t_files *files);

//		FT_PWD.C				//
int		ft_pwd(char **c);

//		FT_CD.C					//
int		ft_cd(char **c, t_files *files);
int		parsing_cd(char **c);
int		ft_user_path(char **c);
char	*ft_home_directory(void);

//		FT_ECHO.C				//
void	ft_echo_arg(char *s);
int		ft_echo(char **cmd);


//		FT_CHECK_BUILTINS.C		//
int		check_built_no_fork(char **c, t_files *files); //exec built
int		check_built_fork(char **c, t_files *files); //exec built
int		check_if_cmd_built(t_cmd cmds); //return (0) si no built ou (1) si built

//		FT_UTILS.C				//
int		ft_iswhitespace(char c);
int		ft_betweenquotes(char *s, int pos);
int		ft_strstrlen(char **s);

//		FT_READLINE.C			//
char	*ft_readline(char *str);
int		ft_path_pos_prompt(void);
char	*ft_read_here_doc(char *prompt, char *eof);

//		FT_NORMALIZE_LINE.C		//
char	*normalize_str(char *s);

//		PARSING_REDIRECTION.C	//
void	parsing_fd(char **str, t_files *files);

//		PARSING_RIGHT_FILE.C	//
int		ft_check_fd(char **fdins, char **fdouts, int nb_pipes);

//		PARSING_

//		FT_EXIT.C				//
void	ft_free_str(char **s);
void	ft_free_cmds(t_mishell *m);
void	ft_free_files(t_files *files);
void	ft_exit(t_mishell *m);

//		FT_SPLIT_MINISHELL.C	//
char	**ft_split_minishell(char const *s, char c);

//		FT_PARSING_CMD.C		//
int		empty_str(const char *s);
int		synthax_check(char *s);

//		FT_INIT_TAB_ENV.C		//
void	ft_init_tab_env(char **env, t_files *files);
void	ft_free_tab_env(t_files *files);
int		ft_tablen(char **tab);

//		FT_MAJ_TAB_ENV.C		//HOME, USER, _ :pas fait  
int		maj_tab_env_oldpwd(t_files *files); //appel en 1er recup pwd pour ca maj
int		maj_tab_env_pwd(t_files *files);

//		FT_GET_PATH_CMD.C		//
char	**ft_get_tab_path(t_files files);
void	ft_init_path_cmd(t_mishell *mish, t_files files, int j);

//		FT_PIPEX.C				//
int		ft_call_pipex(t_mishell mish, t_files *files); //appel pipe -> fork -> dup et exec_cmd
int		open_fdout(t_files files);
int		open_fdin(t_files files); //revoir pour integrer here_doc

//		FT_STRJOIN_PATH.C		//
char	*ft_strjoin_path(char *path, char *cmd);

//		FT_EXEC.C				//
int		ft_exec_cmd(t_mishell mish, t_files files);

#endif
