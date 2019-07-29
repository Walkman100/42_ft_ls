/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:06 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/29 11:38:55 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_elem	*get_folder(char *path, t_args args)
{
	DIR				*dirp;
	struct dirent	*dir_ent;
	MAXUNBR			dircount;
	t_elem			*items;
	int				i;

	dirp = opendir(path);
	dircount = get_folder_count(path, args.all);
	items = (t_elem *)ft_memalloc((dircount + 1) * sizeof(t_elem));
	i = 0;
	while ((dir_ent = readdir(dirp)) != NULL)
	{
		if (filter(args.all, dir_ent->d_name))
		{
			items[i].name = dir_ent->d_name;
			if (args.long_list)
				set_attributes_long(&items[i]);
			else
				set_attributes_short(&items[i]);
			i++;
		}
	}
	items[i].name = 0;
	closedir(dirp);
	return (items);
}
