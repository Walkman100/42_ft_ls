/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:38:14 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/12 14:36:21 by mcarter          ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_args	args;
	int		i;
	char	got_path;
	char	**files;
	char	**folders;
	t_stat	stat_s;

	init_args(&args);
	i = 1;
	got_path = 0;
	files = ft_memalloc(sizeof(*files) * argc);
	folders = ft_memalloc(sizeof(*folders) * argc);
	while (i < argc)
	{
		if (argv[i][0] == '-')
			parse_args(&args, argv[i] + 1);
		else
		{
			got_path = 1;
			stat(argv[i], &stat_s);
			if ((stat_s.st_mode & S_IFDIR) == S_IFDIR && !args.no_recurse)
				add_file(folders, argv[i]);
			else
				add_file(files, argv[i]);
		}
		i++;
	}
	if (*files)
		show_files(files, args);
	if (*files && *folders)
		ft_putchar('\n');
	if (*folders)
		show_folders(folders, args);
	if (!got_path)
	{
		if (args.no_recurse)
		{
			add_file(files, ".");
			show_files(files, args);
		}
		else
			show_folder(".", args);
	}
	ft_memdel((void **)&files);
	ft_memdel((void **)&folders);
	return (0);
}
