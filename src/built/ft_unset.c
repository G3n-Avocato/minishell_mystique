/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:00:32 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/30 19:01:18 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

///verif reaction en cas de faux MY_VAR2 et vrai MY_VAR

int	ft_unset(char **c, t_files *files)//nom variable off //changer losque structur ok
{
	int		i;
	int		j;
	char	*tmp;

	j = 1;
	if (!c[j])
		return (0);
	while (c[j])
	{
		i = 0;
		if (getenv(c[j]) == NULL)
		{
			if (ft_parse_name(c[j]) == 0)
				printf("minishell: unset: `%s' : not a valid identifier\n", c[j]);
			//return un prompt et ne se passe rien
			return (0);
		}
		while (ft_strncmp(files->tab_var_env[i], c[j], ft_strlen(c[j])) != 0 && ft_strlen(c[j]) != ft_strlen(files->tab_var_env[i]))
			i++;
		free(files->tab_var_env[i]);
		while (files->tab_var_env[i] != NULL)
		{
			tmp = files->tab_var_env[i + 1];
			files->tab_var_env[i] = tmp;
			i++;
		}
		j++;
	}
	return (0);
}
