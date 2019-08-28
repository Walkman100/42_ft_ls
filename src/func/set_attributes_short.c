/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_short.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:20:13 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/28 16:30:45 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		set_attributes_short(char *path, t_elem *item)
{
	t_stat	stat_s;
	char	*tmp;

	if (!(tmp = ft_strjoin3(path, "/", (*item).name)))
		exit_e(ENOMEM, "ft_strjoin3 ", __func__);
	if (lstat(tmp, &stat_s) == -1)
		return (put_error_path(errno, tmp, "lstat ", __func__));
	MEMDEL(tmp);
	set_time(item, stat_s);
	parse_mode(stat_s.st_mode, &(*item).type, &(*item).perms);
	(*item).fsize = stat_s.st_size;
	return (0);
}
