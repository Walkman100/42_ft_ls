/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:38:14 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/22 12:08:45 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	init_args(t_args *args)
{
	(*args).long_list = 0;
	(*args).all = 0;
	(*args).noowner = 0;
	(*args).no_recurse = 0;
	(*args).no_sort = 0;
	(*args).reverse_sort = 0;
	(*args).sort_time = 0;
	(*args).sort_access = 0;
	(*args).colour = 0;
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
		if (ft_strncmp(argv[i], "-", 1) == 0)
			parse_args(&args, argv[i]);
		else if (args.recursive)
			ft_putstr("Not implemented\n");
		else
		{
			got_path = 1;
			show_folder(argv[i], args);
		}
		i++;
	}
	if (!got_path)
	{
		if (args.recursive)
			ft_putstr("Not implemented\n");
		else
			show_folder(".", args);
	}
	return (0);
}
