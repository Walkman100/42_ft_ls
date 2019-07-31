/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:19:57 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/30 22:22:43 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	set_attributes_long(char *path, t_elem *item, t_args args)
{
	struct stat	stat_s;
	char		*tmp;

	tmp = ft_strjoin3(path, "/", (*item).name);
	lstat(tmp, &stat_s);
	(*item).atime = stat_s.st_atime;
	(*item).mtime = stat_s.st_mtime;
	(*item).blocks = stat_s.st_blocks;
	parse_mode(stat_s.st_mode, &(*item).type, &(*item).perms);
	(*item).inodes = stat_s.st_nlink;
	(*item).user = parse_user(stat_s.st_uid);
	(*item).group = parse_group(stat_s.st_gid);
	(*item).fsize = stat_s.st_size;
	if (args.sort_access && !args.sort_time)
		(*item).date = get_time_str(stat_s.st_atime);
	else
		(*item).date = get_time_str(stat_s.st_mtime);
	if ((*item).type == 'l')
		(*item).ln_target = get_slink_target(tmp, stat_s.st_size);
	free(tmp);
}
