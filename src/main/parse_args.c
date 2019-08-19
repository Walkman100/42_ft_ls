/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:33:01 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/19 13:53:10 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	init_args(t_args *args)
{
	(*args).columns = 2;
	(*args).long_list = 0;
	(*args).all = 0;
	(*args).no_recurse = 0;
	(*args).recursive = 0;
	(*args).no_sort = 0;
	(*args).reverse_sort = 0;
	(*args).sort_time = 0;
	(*args).sort_access = 0;
	(*args).colour = 0;
	(*args).show_owner = 1;
	(*args).show_group = 1;
	(*args).num_ids = 0;
}

void	parse_flagstr(t_args *args, char *arg_str)
{
	while (*arg_str)
	{
		if (*arg_str == 'A')
			(*args).all = 2;
		else if (*arg_str == 'C')
			(*args).columns = 1;
		else if (*arg_str == 'G')
			(*args).colour = 1;
		else if (*arg_str == 'R')
			(*args).recursive = 1;
		else if (*arg_str == 'a')
			(*args).all = 1;
		else if (*arg_str == 'd')
			(*args).no_recurse = 1;
		else if (*arg_str == 'f')
		{
			(*args).no_sort = 1;
			(*args).all = 1;
		}
		else if (*arg_str == 'g')
		{
			(*args).show_owner = 0;
			(*args).long_list = 1;
		}
		else if (*arg_str == 'l')
			(*args).long_list = 1;
		else if (*arg_str == 'n')
		{
			(*args).num_ids = 1;
			(*args).long_list = 1;
		}
		else if (*arg_str == 'o')
		{
			(*args).show_group = 0;
			(*args).long_list = 1;
		}
		else if (*arg_str == 'r')
			(*args).reverse_sort = 1;
		else if (*arg_str == 't')
			(*args).sort_time = 1;
		else if (*arg_str == 'u')
			(*args).sort_access = 1;
		else if (*arg_str == '1')
			(*args).columns = 0;
		else
		{
			ft_putstr_fd("ft_ls: illegal option -- ", STDERR_FILENO);
			ft_putchar_fd(*arg_str, STDERR_FILENO);
			ft_putstr_fd("\nusage: ls [-ACGRadfglnortu1] [file ...]\n",
				STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		arg_str++;
	}
}

t_args	parse_args(int *count, int argc, char **argv)
{
	t_args	args;

	init_args(&args);
	while (*count < argc && argv[*count][0] == '-')
	{
		if (argv[*count][1] == '\0')
			break ;
		else if (ft_strcmp(argv[*count], "--") == 0)
		{
			(*count)++;
			break ;
		}
		parse_flagstr(&args, argv[*count] + 1);
		(*count)++;
	}
	return (args);
}
