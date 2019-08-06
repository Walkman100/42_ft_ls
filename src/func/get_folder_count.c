/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:25:43 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/06 08:48:56 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

/*
** all:
**  0 = false
**  1 = true
**  2 = no . and .. entries
*/

MAXUNBR	get_folder_count(char *path, unsigned char all)
{
	DIR				*dirp;
	struct dirent	*dir_ent;
	MAXUNBR			i;

	if (!(dirp = opendir(path)))
		return (put_error_path(errno, path, "opendir ", __func__));
	i = 0;
	errno = 0;
	while ((dir_ent = readdir(dirp)) != NULL)
	{
		if (errno)
			return (put_error_path(errno, path, "readdir ", __func__));
		if (filter(all, dir_ent->d_name))
			i++;
	}
	if (closedir(dirp) == -1)
		return (put_error_path(errno, path, "closedir ", __func__));
	return (i);
}
