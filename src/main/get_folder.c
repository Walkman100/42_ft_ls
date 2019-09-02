/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:06 by mcarter           #+#    #+#             */
/*   Updated: 2019/09/02 10:00:55 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		get_folder_dlg(char *path, t_args args, t_dirent *dir_ent, t_elem *item)
{
	if (filter(args.all, dir_ent->d_name))
	{
		(*item).name = ft_strdup(dir_ent->d_name);
		if (args.long_list)
			return (set_attributes_long(path, item, args) ? 0 : 1);
		else
			return (set_attributes_short(path, item) ? 0 : 1);
	}
	return (0);
}

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
			return (put_error_path(errno, path, "rd ", __func__) ? NULL : NULL);
		i += get_folder_dlg(path, args, dir_ent, &items[i]);
		errno = 0;
	}
	items[i].name = 0;
	if (closedir(dirp) == -1)
		return (put_error_path(errno, path, "clsdir ", __func__) ? NULL : NULL);
	return (items);
}
