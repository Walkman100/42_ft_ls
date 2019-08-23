/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 15:57:18 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/23 16:04:44 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

#ifdef __linux__

void	set_time(t_elem *elem, t_stat stat_s)
{
	(*elem).atime = stat_s.st_atim.tv_sec;
	(*elem).atimenano = stat_s.st_atim.tv_nsec;
	(*elem).mtime = stat_s.st_mtim.tv_sec;
	(*elem).mtimenano = stat_s.st_mtim.tv_nsec;
}

#else

void	set_time(t_elem *elem, t_stat stat_s)
{
	(*elem).atime = stat_s.st_atimespec.tv_sec;
	(*elem).atimenano = stat_s.st_atimespec.tv_nsec;
	(*elem).mtime = stat_s.st_mtimespec.tv_sec;
	(*elem).mtimenano = stat_s.st_mtimespec.tv_nsec;
}

#endif
