/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_var_env_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:29:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/06/04 17:38:03 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_join_all_str(t_var_env *data)
{
	char	*buf = NULL;
	char	*tmp = NULL;
	int		new_start;
	int		end;
	int		i;

	i = 0;
	new_start = data->val[i].start - 1;
	end = 0;	
	while (i <= data->nb_dol && end < data->len)
	{
		if (new_start != end)
		{
			buf = ft_substr(data->str, end, new_start - end);
			if (!tmp)
				tmp = ft_strdup(buf);
			else
				tmp = ft_strjoin(tmp, buf);
			end += ft_strlen(buf);
			free(buf);
		}
		if (data->val[i].new_str != NULL)
		{
			tmp = ft_strjoin(tmp, data->val[i].new_str);
			end += data->val[i].len_n + 1;
			i++;
		}
		if (data->val[i].new_str != NULL)
			new_start = data->val[i].start - 1;
		else
			new_start = data->len;
	}
	printf("len = %ld\n", ft_strlen(tmp));
	return (tmp);
}
