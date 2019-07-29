/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_column_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:40:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/29 11:12:42 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

size_t		get_max_width(t_elem *elems)
{
	size_t	maxwidth;
	size_t	tmp;

	maxwidth = 0;
	while ((*elems).name)
	{
		tmp = ft_strlen((*elems).name);
		if (tmp > maxwidth)
			maxwidth = tmp;
		elems++;
	}
	return (maxwidth);
}

t_colinfo	get_column_info(t_elem *elems)
{
	t_colinfo	colinfo;
	size_t		conwidth;

	conwidth = get_tw();
	colinfo.maxwidth = get_max_width(elems) + 1;
	if (conwidth >= (colinfo.maxwidth * 2))
		colinfo.cols = conwidth / colinfo.maxwidth;
	else
		colinfo.cols = 1;
	colinfo.elem_count = get_elem_count(elems);
	colinfo.lines = colinfo.elem_count / colinfo.cols;
	if (colinfo.elem_count % colinfo.cols != 0)
		colinfo.lines++;
	return (colinfo);
}

/*
** 1 2 3 4 5 6 7 8 9
**
** conwidth 7
** maxwidth 2
** cols = 3
** elem_count 9
** lines = 3 (use //)
** elem_count % cols = 0
** lines = 3
**
** 1 2 3
** 4 5 6
** 7 8 9
*/
