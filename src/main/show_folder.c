/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_folder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:18 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/06 08:56:29 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	show_folder(char *path, t_args args)
{
	t_elem	*items;

	if (!(items = get_folder(path, args)))
		return ;
	sort_elem_array(items, args);
	if (args.long_list == 0)
		output_columns(items, args);
	else
	{
		if (items[0].name)
			ft_printf("total %u\n", get_folder_size(items));
		output_lines(items, args);
	}
	if (args.recursive)
		show_folder_subfolders(path, args, items);
}
