/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:24:42 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/12 11:05:17 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	add_file(char **files, char *path)
{
	while (*files)
		files++;
	*files = path;
}

MAXUNBR	arrlen(char **arr)
{
	MAXUNBR	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	show_files(char **files, t_args args)
{
	t_elem	*items;
	int		i;

	items = (t_elem *)ft_memalloc(sizeof(t_elem) * (arrlen(files) + 1));
	i = 0;
	while (*files)
	{
		items[i].name = ft_strdup(*files);
		if (args.long_list)
			i += set_attributes_long((**files == '/') ? "" : ".", &items[i], args);
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

void	show_folders(char **folders, t_args args)
{
	char	*first;
	int		morethanone;

	first = *folders;
	morethanone = (folders[1] ? 1 : 0);
	while (*folders)
	{
		if (first != *folders)
			ft_putchar('\n');
		if (morethanone)
			ft_printf("%s:\n", *folders);
		show_folder(*folders, args);
		folders++;
	}
}
