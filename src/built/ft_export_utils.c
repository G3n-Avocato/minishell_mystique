/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:09:56 by lamasson          #+#    #+#             */
/*   Updated: 2023/05/18 22:08:11 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_one_by_one(char **tab, int i)
{
	int	c;

	c = 0;
	while (tab[i][c] && tab[i + 1][c])
	{
		if (tab[i + 1][c] == '=')
			return (0);
		if (tab[i][c] == '=')
			return (1);
		if (ft_strncmp(tab[i], tab[i + 1], c) > 0)
			return (0);
		if (ft_strncmp(tab[i], tab[i + 1], c) < 0)
			return (1);
		if (ft_strncmp(tab[i], tab[i + 1], c) == 0)
			c++;
	}
	return (1);
}

/* print tab avc declare -x + guillemet
 * et sans var_env _*/

void	ft_print_tab_export(char **tab, int len, int c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < len)
	{
		ft_putstr_fd("declare -x ", 1);
		while (tab[i][j] != '\0')
		{
			ft_putchar_fd(tab[i][j], 1);
			if (tab[i][j] == '=' && c == 0)
			{
				ft_putchar_fd('\"', 1);
				c = 1;
			}
			j++;
		}
		if (c == 1)
			ft_putchar_fd('\"', 1);
		ft_putchar_fd('\n', 1);
		j = 0;
		c = 0;
		i++;
	}
}

/*tri tab ordre alpha*/

void	ft_sort_tab(char **tab, int len)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	while (tab[i] && tab[i + 1])
	{
		if (ft_one_by_one(tab, i) == 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
			continue ;
		}
		i++;
	}
	ft_print_tab_export(tab, len, c);
}

/* malloc nvx tab copy tab_var_env ds nvx tab */

int	ft_export_no_arg(t_files files)
{
	int		len;
	int		i;
	char	**tab;

	i = 0;
	len = ft_tablen(files.tab_var_env);
	tab = malloc(sizeof(char *) * (len + 1));
	if (!tab)
		exit (1);
	while (i < len)
	{
		tab[i] = ft_strdup(files.tab_var_env[i]);
		if (!tab[i])
		{
			ft_free_n_tab(tab, i);
			exit (1);
		}
		i++;
	}
	tab[i] = NULL;
	ft_sort_tab(tab, len);
	ft_free_tab(tab);
	return (0);
} 

/* free le nb de ligne choisi ds le cas
 * d'une erreur de malloc*/

void	ft_free_n_tab(char **tab, int n)
{
	while (n >= 0)
	{
		free(tab[n]);
		n--;
	}
	free(tab);
}
