/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:33:01 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/05 13:58:48 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	parse_args(t_args *args, char *arg_str)
{
	while (*arg_str)
	{
		if (*arg_str == 'l')
			(*args).long_list = 1;
		else if (*arg_str == 'a')
			(*args).all = 1;
		else if (*arg_str == 'A')
			(*args).all = 2;
		else if (*arg_str == 'g')
		{
			(*args).noowner = 1;
			(*args).long_list = 1;
		}
		else if (*arg_str == 'd')
			(*args).no_recurse = 1;
		else if (*arg_str == 'R')
			(*args).recursive = 1;
		else if (*arg_str == 'f')
		{
			(*args).no_sort = 1;
			(*args).all = 1;
		}
		else if (*arg_str == 'r')
			(*args).reverse_sort = 1;
		else if (*arg_str == 't')
			(*args).sort_time = 1;
		else if (*arg_str == 'u')
			(*args).sort_access = 1;
		else if (*arg_str == 'G')
			(*args).colour = 1;
		else if (*arg_str == '1')
			(*args).columns = 0;
		else if (*arg_str == 'C')
			(*args).columns = 1;
		else
			ft_printf("ft_ls: invalid option '%c'\n", *arg_str);
		arg_str++;
	}
}
