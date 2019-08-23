/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:38:14 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/23 08:46:13 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	parse_names(int *count, int argc, char **argv, t_args args)
{
	char	got_path;
	char	**files;
	char	**folders;
	t_stat	stat_s;

	got_path = 0;
	files = ft_memalloc(sizeof(*files) * argc);
	folders = ft_memalloc(sizeof(*folders) * argc);
	while (*count < argc)
	{
		got_path = 1;
		if (stat(argv[*count], &stat_s) == -1)
			put_error_path(errno, argv[*count], "lstat ", __func__);
		else if (ft_strlen(argv[*count]) == 0)
			put_error_path(errno, argv[*count], "emptyName ", __func__);
		else if ((stat_s.st_mode & S_IFDIR) == S_IFDIR && !args.no_recurse)
			add_file(folders, argv[*count]);
		else
			add_file(files, argv[*count]);
		(*count)++;
	}
	if (*files)
		show_files(files, args);
	if (*files && *folders)
		ft_putchar('\n');
	if (*folders)
		show_folders(folders, args);
	MEMDEL(files);
	MEMDEL(folders);
	return (got_path);
}

int		main(int argc, char **argv)
{
	t_args	args;
	int		i;

	i = 1;
	args = parse_args(&i, argc, argv);
	sort_str_array(argv + i, args);
	if (!parse_names(&i, argc, argv, args))
	{
		if (args.no_recurse)
			show_file(".", args);
		else
			show_folder(".", args);
	}
	return (0);
}
