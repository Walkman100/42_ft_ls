/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_columns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:22 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/30 12:45:08 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

/*
** cl = 1 to show colour
** c_ln = current_line counter
*/

void	output_column_n(t_elem *elems, char cl, t_colinfo colinfo, MAXUNBR c_ln)
{
	MAXUNBR	i;
	MAXUNBR	curr_elem_index;
	t_elem	curr_elem;

	i = 0;
	while (i < colinfo.cols)
	{
		curr_elem_index = (colinfo.lines * i) + c_ln;
		if (curr_elem_index < colinfo.elem_count)
		{
			curr_elem = elems[curr_elem_index];
			if (cl)
				output_colour(curr_elem.type, curr_elem.perms);
			if (i + 1 == colinfo.cols)
				putstr_padr_c(curr_elem.name, cl ? RESET : "", \
													ft_strlen(curr_elem.name));
			else
				putstr_padr_c(curr_elem.name, cl ? RESET : "", \
													colinfo.maxwidth);
		}
		i++;
	}
	ft_putchar('\n');
}

void	output_one_column(t_elem *elems, t_args args)
{
	while ((*elems).name)
	{
		if (args.colour)
			output_colour((*elems).type, (*elems).perms);
		ft_putstr((*elems).name);
		if (args.colour)
			put_clr(RESET);
		ft_putchar('\n');
		elems++;
	}
}

void	output_columns(t_elem *elems, t_args args)
{
	t_colinfo	colinfo;
	MAXUNBR		i;

	if (args.columns == 2)
		args.columns = (isatty(STDOUT_FILENO)) ? 1 : 0;
	if (args.columns)
	{
		colinfo = get_column_info(elems);
		i = 0;
		while (i < colinfo.lines)
		{
			output_column_n(elems, args.colour, colinfo, i);
			i++;
		}
	}
	else
		output_one_column(elems, args);
}
