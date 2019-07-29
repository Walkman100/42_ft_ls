/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:40:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/29 11:08:15 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_lineinfo	get_line_info(t_elem *elems)
{
	t_lineinfo	lineinfo;
	MAXUNBR		tmp;

	lineinfo.elem_count = 0;
	lineinfo.inodew = 0;
	lineinfo.userw = 0;
	lineinfo.groupw = 0;
	lineinfo.fsizew = 0;
	lineinfo.namew = 0;
	while ((*elems).name)
	{
		lineinfo.elem_count++;
		tmp = ft_unbrlen((*elems).inodes);
		if (tmp > lineinfo.inodew)
			lineinfo.inodew = tmp;
		tmp = ft_strlen((*elems).user);
		if (tmp > lineinfo.userw)
			lineinfo.userw = tmp;
		tmp = ft_strlen((*elems).group);
		if (tmp > lineinfo.groupw)
			lineinfo.groupw = tmp;
		tmp = ft_nbrlen((*elems).fsize);
		if (tmp > lineinfo.fsizew)
			lineinfo.fsizew = tmp;
		tmp = ft_strlen((*elems).name);
		if (tmp > lineinfo.namew)
			lineinfo.namew = tmp;
		elems++;
	}
	return (lineinfo);
}
