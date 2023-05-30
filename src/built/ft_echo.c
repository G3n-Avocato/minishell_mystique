/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:50:18 by gbertet           #+#    #+#             */
/*   Updated: 2023/04/27 18:46:40 by gbertet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo_arg(char *s)
{
	char	first_quote;
	int		j;

	j = 0;
	first_quote = '\0';
	while (s[j])
	{
		if ((s[j] == '\'' || s[j] == '\"') && first_quote == '\0')
			first_quote = s[j];
		else if (s[j] != first_quote)
			write(1, &s[j], 1);
		j++;
	}
}

int ft_echo(char **cmd)
{
	int i;
	int	nl;

	i = 1;
	nl = 1;
	if (!cmd[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	while (!ft_strncmp(cmd[i], "-n", 3))
	{
		nl = 0;
		i++;
		if (!cmd[i])
			break;
	}
	while (cmd[i])
	{
		ft_echo_arg(cmd[i]);
		i++;
		// if ()
	}
	if (nl)
		write(1, "\n", 1);
	return (0);
}
/*
int	main(int ac, char **av, char **ev)
{
	// char str[3][10] = {"echo", "-n", NULL};
	int	i = 0;
	char **str;

	str = malloc(ac * sizeof(char *));
	while (i + 1 < ac)
	{
		str[i] = ft_strdup(av[i + 1]);
		// write(1, av[i + 1], ft_strlen(av[i + 1]));
		// write(1, " ", 1);
		i++;
	}
	// write(1, "\n", 1);
	execve("/usr/bin/echo", str, ev);
	str[i] = NULL;

	// i = 0;
	// while (i + 1 < ac)
	// {
	// 	str[i] = ft_strdup(av[i + 1]);
	// 	i++;
	// }
	// str[i] = NULL;
	// *av++;
	// av[ac] = NULL;
	// ft_echo(str);
}*/
