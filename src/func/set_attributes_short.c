/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_short.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:20:13 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/26 17:32:04 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	set_attributes_short(t_elem *item)
{
	struct stat	stat_s;

	lstat((*item).name, &stat_s);
	(*item).atime = stat_s.st_atime;
	(*item).mtime = stat_s.st_mtime;
	(*item).type = get_type(&stat_s.st_mode);
}
