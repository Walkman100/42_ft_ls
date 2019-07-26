/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_folder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:18 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/26 13:01:41 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	show_folder(char *path, t_args args)
{
	t_elem	*items;

	items = get_folder(path, args);
	sort_elem_array(items, args);
	if (args.long_list == 0)
		output_columns(items, args);
	else
		output_lines(items, args);
}
