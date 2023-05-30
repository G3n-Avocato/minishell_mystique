/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:27:42 by gbertet           #+#    #+#             */
/*   Updated: 2023/05/26 20:13:39 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		*has_here_doc(char *s, int nb_cmds)
{
	int	*here_doc;
	int	n;
	int	i;

	n = 0;
	i = 0;
	here_doc = malloc(nb_cmds * sizeof(int));
	while (n < nb_cmds)
	{
		here_doc[n] = 0;
		n++;
	}
	n = 0;
	while (n < nb_cmds && s[i])
	{
		if (s[i] == '|' && !ft_betweenquotes(s, i))
			n++;
		else if (s[i] == '<' && s[i + 1] == '<' && !ft_betweenquotes(s, i))
		{
			here_doc[n] = 1;
			i++;
		}
		i++;
	}
	return (here_doc);
}

void	get_cmds(t_mishell *m)
{
	int	i;
	char	**tmp;

	i = 0;
	tmp = ft_split_minishell(m->full_cmd, '|');
	while (tmp[i])
		i++;
	m->nb_cmds = i;
	m->here_doc = has_here_doc(m->full_cmd, m->nb_cmds);
	m->cmds = malloc((m->nb_cmds + 1) * sizeof(t_cmd));
	m->cmds[m->nb_cmds].c = NULL;
	i = -1;
	while (++i < m->nb_cmds)
	{
		m->cmds[i].here_doc = m->here_doc[i];
		m->cmds[i].c = ft_split_minishell(tmp[i], ' ');
	}
	ft_free_str(tmp);
	free(m->here_doc);
}

/*
int main(int ac, char **av, char **ev)
{
	t_mishell	mish;
	char		*prompt;
	char		*tmp;
	int i;
	int j;

	if (getcwd(mish.path, sizeof(mish.path)) == NULL)
    {
        perror("getcwd");
        return (1);
    }
	while (1)
	{
		prompt = ft_strjoin(mish.path, "$ ");
		tmp = ft_readline(prompt);
		free(prompt);
		if (!empty_str(tmp))
		{
			mish.full_cmd = normalize_str(tmp);
			printf("\"%s\"\n", mish.full_cmd);
			if (synthax_check(mish.full_cmd))
			{
				get_cmds(&mish);
				j = 0;
				while (mish.cmds[j].c)
				{
					i = 0;
					while (mish.cmds[j].c[i])
					{
						printf("\"%s\" ", mish.cmds[j].c[i]);
						i++;
					}
					printf("\n");
					j++;
				}
				if (!ft_strncmp(mish.full_cmd, "exit", 4))
					ft_exit(&mish);
				ft_free_cmds(&mish);
			}
		}
		free(tmp);
	}
	free(tmp);
	free(prompt);
	free(mish.full_cmd);
}*/
