/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_folder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:18 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/22 09:59:46 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	show_folder(char *path, t_args args)
{
	t_elem	*items;
	int		i;

	if (args.long_list == 0)
	{
		items = get_folder_short(path, args);
		sort_elem_array(items, args);
		output_columns(items, args);
	}
	else
	{
		items = get_folder_long(path, args);
		sort_elem_array(items, args);
		i = 0;
		while (items[i].name)
		{
			output_line(items[i], args);
			i++;
		}
	}
}
