/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:00:32 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/16 19:27:57 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//unset MY_VAR MY_VAR1 MY_VAR2 
////boucle possible dans la fct appelant ft_unset pour executer unset a la suite
///verif reaction en cas de faux MY_VAR2 et vrai MY_VAR

int	ft_unset(char **c, t_files *files)//nom variable off //changer losque structur ok
{
	int		i;
	char	*tmp;

	i = 0;
	if (!c[1])
		return (0);
	if (getenv(c[1]) == NULL)
	{
		if (ft_parse_name(c[1]) == 0)
			printf("minishell: unset: `%s' : not a valid identifier\n", c[1]);
		//return un prompt et ne se passe rien
		return (0);
	}
	while (ft_strncmp(files->tab_var_env[i], c[1], ft_strlen(c[1])) != 0 && ft_strlen(c[1]) != ft_strlen(files->tab_var_env[i]))
		i++;
	free(files->tab_var_env[i]);
	while (files->tab_var_env[i] != NULL)
	{
		tmp = files->tab_var_env[i + 1];
		files->tab_var_env[i] = tmp;
		i++;
	}
	return (0);
}
