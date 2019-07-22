/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_columns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:22 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/22 16:36:00 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	output_column_n(t_elem *elems, char colour, t_colinfo colinfo, size_t curr_line)
{
	// IN PROGRESS
	size_t	i;
	t_elem	curr_elem;

	i = 0;
	while (i < colinfo.cols)
	{
		curr_elem = elems[(colinfo.lines * i) + curr_line];
		if (colour)
			output_colour(curr_elem.type);
		putstr_padr(curr_elem.name, colinfo.maxwidth);
		if (colour)
			put_clr(RESET);
		i++;
	}
}

void	output_columns(t_elem *elems, t_args args)
{
	t_colinfo	colinfo;
	size_t		i;

	colinfo = get_column_info(elems);
	while (i < colinfo.lines)
	{
		output_column_n(elems, args.colour, colinfo, i);
		i++;
	}
}
