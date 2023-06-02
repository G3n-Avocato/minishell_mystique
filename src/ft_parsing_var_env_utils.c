/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_var_env_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:29:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/06/02 18:48:26 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_join_all_str(t_var_env *data)
{
	char	*final_s;
	char	*buf;
	char	*tmp;
	int		len_p;
	int		i;

	i = 0;
	if (data->val[0].start > 1)
	{
		buf = ft_substr(data->str, 0, data->val[0].start - 2);
		buf = ft_strjoin(buf, data->val[i].new_str);
	}
	len_p = data->val[i].start + data->val[i].len_n; 
	while (i < data->nb_dol)
	{
		if (data->val[i + 1] && len_p == data->val[i + 1].start)
			tmp = ft_strjoin(data->val[i].new_str, data->val[i + 1]);
		len_p = data->val[i].start + data->val[i].len_n; 
		else if (i + 1 == data->nb_dol && data->str[len_p] != len  )
		{

			buf = ft_substr(data->str, len_p, len - len_p);

		}


	}



}
