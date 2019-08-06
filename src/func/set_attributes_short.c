/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_short.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:20:13 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/06 11:41:19 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	set_attributes_short(char *path, t_elem *item)
{
	t_stat	stat_s;
	char	*tmp;

	if (!(tmp = ft_strjoin3(path, "/", (*item).name)))
		exit_e(ENOMEM, "ft_strjoin3 ", __func__);
	if (lstat(tmp, &stat_s) == -1)
		exit_path(errno, path, "lstat ", __func__);
	free(tmp);
	(*item).atime = stat_s.st_atime;
	(*item).mtime = stat_s.st_mtime;
	parse_mode(stat_s.st_mode, &(*item).type, &(*item).perms);
}
