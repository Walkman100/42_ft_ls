/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_short.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:20:13 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/02 16:34:42 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	set_attributes_short(char *path, t_elem *item)
{
	struct stat	stat_s;
	char		*tmp;

	tmp = ft_strjoin3(path, "/", (*item).name);
	lstat(tmp, &stat_s);
	free(tmp);
	(*item).atime = stat_s.st_atime;
	(*item).mtime = stat_s.st_mtime;
	parse_mode(stat_s.st_mode, &(*item).type, &(*item).perms);
}
