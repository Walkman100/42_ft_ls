/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:30 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/29 11:11:04 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	output_line(t_elem elem, t_lineinfo lineinfo, t_args args)
{
	ft_printf("%c%s ", elem.type, elem.perms);
	putnbr_padl(elem.inodes, lineinfo.inodew);
	ft_putchar(' ');
	putstr_padr(elem.user, lineinfo.userw);
	putstr_padr(elem.group, lineinfo.groupw);
	putnbr_padl(elem.fsize, lineinfo.fsizew);
	ft_printf(" %s ", elem.date);
	if (args.colour)
		output_colour(elem.type);
	ft_putstr(elem.name);
	if (args.colour)
		put_clr(RESET);
	if (elem.type == 'l')
		ft_printf(" -> %s", elem.ln_target);
	ft_putchar('\n');
}

void	output_lines(t_elem *elems, t_args args)
{
	t_lineinfo	lineinfo;
	size_t		i;

	lineinfo = get_line_info(elems);
	i = 0;
	while (i < lineinfo.elem_count)
	{
		output_line(elems[i], lineinfo, args);
		i++;
	}
}
