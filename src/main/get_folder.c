/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:06 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/29 16:40:20 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_elem	*get_folder(char *path, t_args args)
{
	DIR			*dirp;
	t_dirent	*dir_ent;
	MAXUNBR		dircount;
	t_elem		*items;
	int			i;

	if ((dircount = get_folder_count(path, args.all)) == (MAXUNBR)-1)
		return (NULL);
	if (!(dirp = opendir(path)))
		return (put_error_path(errno, path, "opndir ", __func__) ? NULL : NULL);
	if (!(items = (t_elem *)ft_memalloc(sizeof(t_elem) * (dircount + 1))))
		exit_e(ENOMEM, "ft_memalloc ", __func__);
	i = 0;
	errno = 0;
	while ((dir_ent = readdir(dirp)) != NULL)
	{
		if (errno)
			return (put_error_path(errno, path, "readdir ", __func__) ? NULL : NULL);
		if (filter(args.all, dir_ent->d_name))
		{
			items[i].name = ft_strdup(dir_ent->d_name);
			if (args.long_list)
				set_attributes_long(path, &items[i], args);
			else
				set_attributes_short(path, &items[i]);
			i++;
		}
		errno = 0;
	}
	items[i].name = 0;
	if (closedir(dirp) == -1)
		return (put_error_path(errno, path, "clsdir ", __func__) ? NULL : NULL);
	return (items);
}
