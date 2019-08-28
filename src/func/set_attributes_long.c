/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:19:57 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/28 15:56:07 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		set_attributes_long(char *path, t_elem *item, t_args args)
{
	t_stat	stat_s;
	char	*tmp;

	if (!(tmp = ft_strjoin3(path, "/", (*item).name)))
		exit_e(ENOMEM, "ft_strjoin3 ", __func__);
	if (lstat(tmp, &stat_s) == -1)
		return (put_error_path(errno, tmp, "lstat ", __func__));
	set_time(item, stat_s);
	(*item).blocks = stat_s.st_blocks;
	parse_mode(stat_s.st_mode, &(*item).type, &(*item).perms);
	(*item).perms[9] = get_extra_char(tmp);
	(*item).inodes = stat_s.st_nlink;
	(*item).user = parse_user(stat_s.st_uid, args.num_ids);
	(*item).group = parse_group(stat_s.st_gid, args.num_ids);
	if ((*item).type == 'b' || (*item).type == 'c')
		(*item).fsize = stat_s.st_rdev;
	else
		(*item).fsize = stat_s.st_size;
	if (args.sort_access)
		(*item).date = get_time_str((*item).atime);
	else
		(*item).date = get_time_str((*item).mtime);
	if ((*item).type == 'l')
		(*item).ln_target = get_slink_target(tmp, stat_s.st_size);
	MEMDEL(tmp);
	return (0);
}
