/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:24:42 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/30 12:18:52 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	add_file(char **files, char *path)
{
	while (*files)
		files++;
	*files = path;
}

void	show_file(char *file, t_args args)
{
	char	**files;

	files = ft_memalloc(sizeof(*files) * 2);
	add_file(files, file);
	show_files(files, args);
	MEMDEL(files);
}

void	show_files(char **files, t_args args)
{
	t_elem	*items;
	int		i;

	items = (t_elem *)ft_memalloc(sizeof(t_elem) * (str_arr_len(files) + 1));
	i = 0;
	while (*files)
	{
		items[i].name = ft_strdup(*files);
		if (args.long_list)
			i += set_attributes_long((**files == '/') ? "" : ".", &items[i], \
																		args);
		else
			i += set_attributes_short((**files == '/') ? "" : ".", &items[i]);
		i++;
		files++;
	}
	items[i].name = 0;
	sort_elem_array(items, args);
	if (args.long_list == 0)
		output_columns(items, args);
	else
		output_lines(items, args);
	free_items(&items);
}

t_elem	*get_folders_info(char **folders)
{
	t_elem	*items;
	int		i;

	items = (t_elem *)ft_memalloc(sizeof(t_elem) * (str_arr_len(folders) + 1));
	i = 0;
	while (*folders)
	{
		items[i].name = ft_strdup(*folders);
		if (set_attributes_short((**folders == '/') ? "" : ".", &items[i]) == 0)
			i++;
		else
			MEMDEL(items[i].name);
		folders++;
	}
	items[i].name = NULL;
	return (items);
}

void	show_folders(char **folders, t_args args, char forceshow)
{
	t_elem	*items;
	int		i;
	int		morethanone;

	morethanone = (folders[1] ? 1 : 0);
	morethanone = (forceshow ? 1 : morethanone);
	items = get_folders_info(folders);
	sort_elem_array(items, args);
	i = 0;
	while (items[i].name)
	{
		if (i)
			ft_putchar('\n');
		if (morethanone)
			ft_printf("%s:\n", items[i].name);
		show_folder(items[i].name, args);
		i++;
	}
	free_items(&items);
}
