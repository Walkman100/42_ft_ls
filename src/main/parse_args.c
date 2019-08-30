/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:33:01 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/30 10:59:36 by mcarter          ###   ########.fr       */
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
	(*args).sort_size = 0;
	(*args).colour = 0;
	(*args).show_owner = 1;
	(*args).show_group = 1;
	(*args).num_ids = 0;
}

/*
** parse_flagstr is split up into 3 functions because of number of lines
** (was 59 lines)
**
** parse_flagstr1 and -2 return (1) if they have parsed an arg, 0 if not
*/

int		parse_flagstr1(t_args *args, char arg)
{
	if (arg == 'A')
		(*args).all = (*args).all ? (*args).all : 2;
	else if (arg == 'C')
		(*args).columns = 1;
	else if (arg == 'G')
		(*args).colour = 1;
	else if (arg == 'R')
		(*args).recursive = 1;
	else if (arg == 'S')
		(*args).sort_size = 1;
	else if (arg == 'a')
		(*args).all = 1;
	else if (arg == 'd')
		(*args).no_recurse = 1;
	else if (arg == 'f')
	{
		(*args).no_sort = 1;
		(*args).all = 1;
	}
	else if (arg == 'l')
		(*args).long_list = 1;
	else
		return (0);
	return (1);
}

int		parse_flagstr2(t_args *args, char arg)
{
	if (arg == 'g')
	{
		(*args).show_owner = 0;
		(*args).long_list = 1;
	}
	else if (arg == 'n')
	{
		(*args).num_ids = 1;
		(*args).long_list = 1;
	}
	else if (arg == 'o')
	{
		(*args).show_group = 0;
		(*args).long_list = 1;
	}
	else if (arg == 'r')
		(*args).reverse_sort = 1;
	else if (arg == 't')
		(*args).sort_time = 1;
	else if (arg == 'u')
		(*args).sort_access = 1;
	else
		return (0);
	return (1);
}

void	parse_flagstr(t_args *args, char *arg_str)
{
	while (*arg_str)
	{
		if (!parse_flagstr1(args, *arg_str) && !parse_flagstr2(args, *arg_str))
		{
			if (*arg_str == '1')
			{
				(*args).columns = 0;
				(*args).long_list = 0;
			}
			else
			{
				ft_putstr_fd("ft_ls: illegal option -- ", STDERR_FILENO);
				ft_putchar_fd(*arg_str, STDERR_FILENO);
				ft_putstr_fd("\nusage: ls [-ACGRSadfglnortu1] [file ...]\n",
					STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
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
		else if (ft_strequ(argv[*count], "--"))
		{
			(*count)++;
			break ;
		}
		parse_flagstr(&args, argv[*count] + 1);
		(*count)++;
	}
	return (args);
}
