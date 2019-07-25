/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 10:25:43 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/25 12:24:53 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

/*
** all:
**  0 = false
**  1 = true
**  2 = no . and .. entries
*/

MAXUNBR	get_folder_count(char *path, char all)
{
	DIR				*dirp;
	struct dirent	*dir_ent;
	MAXUNBR			i;

	dirp = opendir(path);
	i = 0;
	while ((dir_ent = readdir(dirp)) != NULL)
	{
		if (all || dir_ent->d_name[0] != '.')
		{
			if (all != 2 || (ft_strcmp(dir_ent->d_name, ".") != 0 && \
							ft_strcmp(dir_ent->d_name, "..") != 0))
				i++;
		}
	}
	closedir(dirp);
	return (i);
}
