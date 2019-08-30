/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:38:14 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/30 13:10:13 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		parse_as_folder(char *path, t_args args)
{
	t_stat	stat_s;

	if (args.no_recurse)
		return (0);
	if (stat(path, &stat_s) == -1 && lstat(path, &stat_s) == -1)
		return (put_error_path(errno, path, "stat/lstat ", __func__));
	else if ((stat_s.st_mode & S_IFDIR) == S_IFDIR)
	{
		if (!args.long_list)
			return (1);
		lstat(path, &stat_s);
		if ((stat_s.st_mode & S_IFLNK) == S_IFLNK)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

void	parse_names_delegate(char **files, char **folders, t_args args, int shw)
{
	if (*files)
		show_files(files, args);
	if (*files && *folders)
		ft_putchar('\n');
	if (*folders)
		show_folders(folders, args, shw);
}

char	parse_names(int *count, int argc, char **argv, t_args args)
{
	char	got_path;
	char	**files;
	char	**folders;
	int		encountered_error;
	int		parse_as_folder_b;

	got_path = 0;
	files = ft_memalloc(sizeof(*files) * argc);
	folders = ft_memalloc(sizeof(*folders) * argc);
	encountered_error = 0;
	while (*count < argc)
	{
		got_path = 1;
		if ((parse_as_folder_b = parse_as_folder(argv[*count], args)) == -1)
			encountered_error = 1;
		else if (parse_as_folder_b)
			add_file(folders, argv[*count]);
		else
			add_file(files, argv[*count]);
		(*count)++;
	}
	parse_names_delegate(files, folders, args, encountered_error);
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
