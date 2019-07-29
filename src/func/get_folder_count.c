/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:25:43 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/29 11:40:25 by mcarter          ###   ########.fr       */
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

	dirp = opendir(path);
	i = 0;
	while ((dir_ent = readdir(dirp)) != NULL)
		if (filter(all, dir_ent->d_name))
			i++;
	closedir(dirp);
	return (i);
}
