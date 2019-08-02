/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:59:56 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/02 11:53:59 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	show_folder_subfolders(char *path, t_args args, t_elem *items)
{
	char			*tmp;

	while ((*items).name)
	{
		if (filter(2, (*items).name) && (*items).type == 'd')
		{
			tmp = ft_strjoin3(path, "/", (*items).name);
			ft_printf("\n%s:\n", tmp);
			show_folder(tmp, args);
			ft_memdel((void **)&tmp);
		}
		items++;
	}
}
