/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:16:03 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/16 22:11:28 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//fct en test
char *ft_readline(char *str)
{
	char    *line;

	line = readline(str);
	if (line)
	{
		add_history(line);
		return (line);		
	}
	else
		return (ft_strdup("exit"));
}

/* fct recup PWD est l'envoie
 * a readline pour afficher
 * nouveau prompt avec nouvelle
 * position de l'utilisateur
 * appeler a chaque nouvelle saisie
 * dans terminal*/

int	ft_path_pos_prompt(void)
{
	char	*pwd;

	pwd = malloc(sizeof(char *) * 1024);
	if (pwd == NULL)
		exit (1);
	if (getcwd(pwd, 1024) == NULL)
	{
		perror(strerror(errno));
		free(pwd);
		return (1);
	}
	//ft_readline(pwd);
	free(pwd);
	return (0);
}

char	*ft_read_here_doc(char *prompt, char *eof)
{
	char	*line;

	line = readline(prompt);
	if (line)
		return (ft_strjoin(line, "\n"));
	else
		return (eof);
}
