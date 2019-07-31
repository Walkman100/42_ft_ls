/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:23:01 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/30 22:04:56 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

/*
** adding 511 means that the number floor divided by 512 will always result in
** the total amount of 512 blocks the file takes up
*/

MAXUNBR	get_folder_size(t_elem *elems)
{
	MAXUNBR	rtn;

	rtn = 0;
	while ((*elems).name)
	{
		rtn += ((*elems).fsize + 511) / 512;
		elems++;
	}
	return (rtn);
}
