/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:38:14 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/05 13:57:28 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	init_args(t_args *args)
{
	(*args).long_list = 0;
	(*args).all = 0;
	(*args).noowner = 0;
	(*args).no_recurse = 0;
	(*args).recursive = 0;
	(*args).no_sort = 0;
	(*args).reverse_sort = 0;
	(*args).sort_time = 0;
	(*args).sort_access = 0;
	(*args).colour = 0;
	(*args).columns = 2;
}

int		main(int argc, char **argv)
{
	t_args	args;
	int		i;
	char	got_path;

	init_args(&args);
	i = 1;
	got_path = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			parse_args(&args, argv[i] + 1);
		else
		{
			got_path = 1;
			show_folder(argv[i], args);
		}
		i++;
	}
	if (!got_path)
		show_folder(".", args);
	return (0);
}
