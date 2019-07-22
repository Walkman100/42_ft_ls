/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:02:15 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/22 11:30:29 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	set_attributes(t_elem *item)
{
	struct stat	stat_s;

	lstat((*item).name, &stat_s);
	(*item).atime = stat_s.st_atimespec.tv_sec;
	(*item).mtime = stat_s.st_mtimespec.tv_sec;
	(*item).type = get_type(stat_s.st_mode);
}

t_elem	*get_folder_short(char *path, t_args args)
{
	DIR				*dirp;
	struct dirent	*dir_ent;
	MAXUNBR			dircount;
	t_elem			*items;
	int				i;

	dirp = opendir(path);
	dircount = get_item_count(path, args.all);
	items = (t_elem *)ft_memalloc((dircount + 1) * sizeof(t_elem));
	i = 0;
	while ((dir_ent = readdir(dirp)) != NULL)
	{
		if (args.all || ft_strncmp(dir_ent->d_name, ".", 1) != 0)
		{
			items[i].name = dir_ent->d_name;
			set_attributes(&items[i]);
			i++;
		}
	}
	items[i].name = 0;
	closedir(dirp);
	return (items);
}
