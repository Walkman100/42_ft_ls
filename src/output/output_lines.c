/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:30 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/29 22:24:23 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	put_driver_id(t_elem elem, MAXUNBR padding)
{
	putnbr_padl(major(elem.fsize), padding - 5);
	ft_putchar(',');
	putnbr_padl(minor(elem.fsize), 4);
}

void	output_line(t_elem elem, t_lineinfo lineinfo, t_args args)
{
	ft_printf("%c%s", elem.type, elem.perms);
	putnbr_padl(elem.inodes, lineinfo.inodew);
	ft_putchar(' ');
	if (args.show_owner)
		putstr_padr(elem.user, lineinfo.userw);
	if (args.show_owner && args.show_group)
		ft_putstr("  ");
	if (args.show_group)
		putstr_padr(elem.group, lineinfo.groupw);
	if (elem.type == 'b' || elem.type == 'c')
		put_driver_id(elem, lineinfo.fsizew);
	else
		putnbr_padl(elem.fsize, lineinfo.fsizew);
	ft_printf(" %s ", elem.date);
	if (args.colour)
		output_colour(elem.type, elem.perms);
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
