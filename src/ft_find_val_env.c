/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_val_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:57:23 by lamasson          #+#    #+#             */
/*   Updated: 2023/06/02 16:07:03 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//parse verif double simple quote ou rien 
//recuperer la str verifier
//compter avant compter apres et compter le user correspondant
//malloc taille 
//strjoin

//    ft_display_var_env ----- ft_parsing_simple_double_quote

/*
 * Parsing NAME variable d'environnement bien ecrit
 */

/* check si $ pour name_var_env si oui
 * return pos '$' si non return -1 pas
 * de var_env */
/*
int	ft_check_dollar(char *str) //if 0 good if 1 not good 
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (-1);
}
*/
/* fct roulette tab_var_env recherche d ela bonne var_env,
 * ? getenv ne peut pas etre utiliser puisqu'il s'appuit sur le vrai env ?
 * ft_getenv_perso qui se repete pour tout le tableau, lorsque tab_env fin 
 * return un nvx name avec un char en - afin de detecter le bon name 
 * ex  : $USERlsjjdc */
/*
char	*rec_name_var_env(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] != '=')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	name = ft_substr(str, 0, i);
	if (!name)
		exit (1);
	return (name);
}

char	*ft_wheel_tab_var_env(t_files files, char *name, int len_n)
{
	int		i;
	int		len_tmp;
	int		len_val;
	char	*tmp;

	i = 0;
	while (files.tab_var_env[i] != NULL)
	{
		tmp = rec_name_var_env(files.tab_var_env[i]);
		len_tmp = ft_strlen(tmp);
		if (ft_strncmp(tmp, name, len_tmp) == 0 && len_tmp == len_n)
		{
			free(tmp);
			len_val = ft_strlen(files.tab_var_env[i]);
			tmp = ft_substr(files.tab_var_env[i], len_tmp + 1, len_val - (len_tmp + 1));
			return (tmp);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*ft_rec_str_trad(t_files files, char *str, int d)
{
	char 	*new;
	char	*name;
	int		len;

	len = ft_strlen(str);
	while (len > d)
	{
		name = ft_substr(str, d, len - d);
		new = ft_wheel_tab_var_env(files, name, len - d);
		free(name);
		if (new != NULL)
			break ;
		len--;
	}
	return (new);
}
*/
/* A gerer : cas '' / ""
 * dif entre: echo $PWD / $PWD 
 * printf val_env / recupere val_env et exec comme une cmd ds bash
 * */
//parsing $ a revoir + voir gestion erreur en cas de variable inexistante +n parsing quote et double / puis renvoyer la chaine de caractere pas la print
/*int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	int	i = 0;
	t_files	files;
	char *str;
	char *ar;

	ar = "$PWDddd";
	ft_init_tab_env(env, &files);
	
	i = ft_check_dollar(ar);
	if (i == -1)
		return (1);
	str = ft_rec_str_trad(files, ar, i);
	printf("%s\n", str);	

	free(str);
	ft_free_tab_env(&files);
	return (0);
}*/
