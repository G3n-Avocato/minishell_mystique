/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:02:12 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/16 19:20:34 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(char **c)
{
	char	*pwd;

	pwd = malloc(sizeof(char *) * 1024);
	if (pwd == NULL) //secu malloc
		exit (1); //free en cas d'erreur de la fct malloc
	if (getcwd(pwd, 1024) == NULL) //obtien path pos
	{
		printf("minishell: %s: %s\n", c[0], strerror(errno));
		free(pwd);
		return (1);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
