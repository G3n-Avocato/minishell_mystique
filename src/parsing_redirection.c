/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:09:03 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/26 20:14:30 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* return une string malloc avec le nom
 * du fichier d'entrer ou de sortit*/

// char	*rec_file(char *str)
// {
// 	// int		y;
// 	char	*file;

// 	// y = i;
// 	// while (ft_iswhitespace(str[y]) == 0)
// 	// 	y++;
// 	// file = ft_substr(str, i, y - i);
// 	file = ft_strdup(str);
// 	if (file == NULL)
// 		exit (1); //fct de free necessaire suivant pos dans cod
// 	return (file);
// }

/* check redirection out
 * if classic or append mode:
 * '>' '>>' '>>>'
 * return int out; in struct files
 * si 1 out = 0
 * si 2 out = 1 (output append mode)
 * si 3 exit print error*/

int	redirect_out(char *str)
{
	int	out;

	if (!ft_strncmp(str, ">", 2))
		out = 0;
	else if (!ft_strncmp(str, ">>", 3))
		out = 1;
	else
	{
		printf("minsihell: syntax error near unexpected token `>'\n");
		exit (1);
	}
	return (out);
}

/* cherche redirection in dans str:
 * str est la string passé dans le terminal,
 * t_files *fd est la struct ou sont stockés
 * le fd du fichier in et du fichier out
 *
 * fct ne check pas d'erreur pour le moment
 * puisque check du here doc dans ft_parsing_cmd.c
 *
 * if fd_in trouvé malloc puis placé dans struct files
 * else fd_in = NULL*/

char	**find_redirect_left(char **str)
{
	int		i;
	int		j;
	char	**fdins;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], "<", 2))
			j++;
		i++;
	}
	i = 0;
	fdins = malloc((j + 1) * sizeof(char *));
	fdins[j] = NULL;
	j = 0;
	while (str[i])
	{
		if (!ft_strncmp(str[i], "<", 2))
			fdins[j++] = ft_strdup(str[++i]);
		i++;
	}
	return (fdins);
}

/* same left-right exept for int out;
 * mis a -1 if no redirection de sortit
 * et fd_out = NULL*/

char	**find_redirect_right(char **str, t_files *fd)
{
	int		i;
	int		j;
	char	**fdouts;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (!ft_strncmp(str[i], ">", 1))
			j++;
	}
	i = -1;
	fdouts = malloc((j + 1) * sizeof(char *));
	fdouts[j] = NULL;
	j = 0;
	while (str[++i])
	{
		if (!ft_strncmp(str[i], ">", 1))
		{
			fd->out = redirect_out(str[i]);
			fdouts[j++] = ft_strdup(str[++i]);
		}
	}
	return (fdouts);
}

void	set_fd(char **fdins, char **fdouts, t_files *fd)
{
	int	i;

	i = 0;
	while (fdins[i])
		i++;
	if (i)
		fd->fd_in = ft_strdup(fdins[--i]);
	else
		fd->fd_in = NULL;
	i = 0;
	while (fdouts[i])
		i++;
	if (i)
		fd->fd_out = ft_strdup(fdouts[--i]);
	else
	{
		fd->fd_out = NULL;
		fd->out = -1;
	}
	fd->err = 0;
}

/* fct regroupe parsing redirection in-out,
 * check int et out chmod
 * et recuperation du nom des fichiers fd_in et fd_out
 * dans struct files*/

void	parsing_fd(char **str, t_files *fd)
{
	char	**fdins;
	char	**fdouts;

	fdins = find_redirect_left(str);
	fdouts = find_redirect_right(str, fd);
	if (!ft_check_fd(fdins, fdouts, ft_strstrlen(str) - 1))
		set_fd(fdins, fdouts, fd);
	else
	{
		fd->fd_in = NULL;
		fd->fd_out = NULL;
		fd->err = 1;
	}
	ft_free_str(fdins);
	ft_free_str(fdouts);
}

/* main_test parsing_redirection.c et parsing_right_file.c
 */
/*
int main(void)
{
	char **str;
	t_files fd;

	str = malloc(10 * sizeof(char *));
	str[9] = NULL;
	str[0] = ft_strdup("<");
	str[1] = ft_strdup("out");
	str[2] = ft_strdup("<");
	str[3] = ft_strdup("out2");
	str[4] = ft_strdup("commande");
	str[5] = ft_strdup(">");
	str[6] = ft_strdup("ah");
	str[7] = ft_strdup(">");
	str[8] = ft_strdup("bh");
	parsing_fd(str, &fd);
	printf("%s\n", fd.fd_in);
	printf("%s\n", fd.fd_out);
	printf("%d\n", fd.out);
	ft_free_str(str);
	if (fd.fd_in)
		free(fd.fd_in);
	if (fd.fd_out)
		free(fd.fd_out);
}*/
