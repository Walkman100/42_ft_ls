/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:06 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/07 15:56:41 by mcarter          ###   ########.fr       */
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

	if ((dircount = get_folder_count(path, args.all)) == (MAXUNBR)-1)
		return (NULL);
	if (!(dirp = opendir(path)))
	{
		put_error_path(errno, path, "opendir ", __func__);
		return (NULL);
	}
	if (!(items = (t_elem *)ft_memalloc(sizeof(t_elem) * (dircount + 1))))
	{
		put_error(ENOMEM, "ft_memalloc ", __func__);
		return (NULL);
	}
	i = 0;
	errno = 0;
	while ((dir_ent = readdir(dirp)) != NULL)
	{
		if (errno)
		{
			put_error_path(errno, path, "readdir ", __func__);
			return (NULL);
		}
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
	{
		put_error_path(errno, path, "closedir ", __func__);
		return (NULL);
	}
	return (items);
}
