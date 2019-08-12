/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:44 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/12 14:42:03 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*parse_group(gid_t gid, char noparse)
{
	struct group	*gr_s;

	if (noparse)
		return (ft_itoa(gid));
	errno = 0;
	gr_s = getgrgid(gid);
	if (gr_s)
		return (ft_strdup(gr_s->gr_name));
	else if (errno)
		put_error(errno, "getgrgid ", __func__);
	return (ft_itoa(gid));
}
