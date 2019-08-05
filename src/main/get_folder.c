/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:06 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/05 16:49:27 by mcarter          ###   ########.fr       */
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

	dircount = get_folder_count(path, args.all);
	if (!(dirp = opendir(path)))
		exit_path(errno, path, "opendir ", __func__);
	items = (t_elem *)ft_memalloc((dircount + 1) * sizeof(t_elem));
	i = 0;
	errno = 0;
	while ((dir_ent = readdir(dirp)) != NULL)
	{
		if (errno)
			exit_e(errno, "readdir ", __func__);
		if (filter(args.all, dir_ent->d_name))
		{
			items[i].name = ft_strdup(dir_ent->d_name);
			if (args.long_list)
				set_attributes_long(path, &items[i], args);
			else
				set_attributes_short(path, &items[i]);
			i++;
		}
	}
	items[i].name = 0;
	if (closedir(dirp) == -1)
		exit_e(errno, "closedir ", __func__);
	return (items);
}
