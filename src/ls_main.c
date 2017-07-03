/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:02:00 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/06/21 16:15:28 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_params	*init_param()
{
	t_params	*par;

	par = (t_params*)malloc(sizeof(t_params));
	par->options = NULL;
	return (par);
}

int		is_option(char *arg)
{
	int		i;

	i = 0;
	if (!arg)
		return (FALSE);
	if (arg[i++] != '-')
		return (FALSE);
//	while (arg[i])
//	{
//		if (!ft_strchr(AVAILIBLE_OPTIONS, arg[i]))
//			return (FALSE);
//		i++;
//	}
	return (TRUE);
}

int		option_exist(char option, t_params *par)
{
	if (!par->options)
		return (FALSE);
	if (ft_strchr(par->options, option))
		return (TRUE);
	else
		return (FALSE);
}

void	add_option(char option, t_params *par)
{
	char	*tmp;
	int		len;

	if (!par->options)
	{
		par->options = ft_strnew(1);
		par->options[0] = option;
	}
	else
	{
		tmp = par->options;
		len = ft_strlen(tmp);
		par->options = ft_strnew(len + 1);
		ft_memmove(par->options, tmp, len);
		par->options[len] = option;
		free(tmp);
	}
}

int		parse_options(t_params *par, char **av)
{
	int		arg_index;
	int		i;

	arg_index = 1;
	while (av[arg_index])
	{
		if (is_option(av[arg_index]))
		{
			i = 1;
			while (av[arg_index][i])
			{
				if (!ft_strchr(AVAILIBLE_OPTIONS, av[arg_index][i]))
					return (int)(av[arg_index][i]);
				if (!option_exist(av[arg_index][i], par))
				{
					add_option(av[arg_index][i], par);
				}
				i++;
			}
		}
		else
		{
			par->dirs = &av[arg_index];
			break;
		}
		arg_index++;
	}
	return (FALSE);
}

void	show_usage(char option)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(option);
	ft_putendl("");
	ft_putstr("usage: ft_ls [-");
	ft_putstr(AVAILIBLE_OPTIONS);
	ft_putendl("] [file ...]");
}

int		main(int ac, char **av)
{
	t_params		*par;
	int 			i;
	int 			false_option;
	DIR				*curr_dir;
	struct dirent	*next_obj;

	i = 0;
	if (ac > 1)
	{
		par = init_param();
		false_option = parse_options(par, av);
		if (false_option)
			show_usage(false_option);
		ft_putstr("Options: ");
		ft_putendl(par->options);
		ft_putstr("Directories:\n");
		while(par->dirs[i])
		{
			ft_putendl(par->dirs[i]);
			i++;
		}
	}
	curr_dir = opendir(par->dirs[0]);
	if (curr_dir)
	{
		printf("\n\nDir \"%s\" is opened\n-----------------------\n", par->dirs[0]);
	}
	while (next_obj = readdir(curr_dir))
	{
		printf("%s\n", next_obj->d_name);
	}
	return (0);
}