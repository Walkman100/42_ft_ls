/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_folder_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:23:01 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/30 22:58:57 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

MAXUNBR	get_folder_size(t_elem *elems)
{
	MAXUNBR	rtn;

	rtn = 0;
	while ((*elems).name)
	{
		rtn += (*elems).blocks;
		elems++;
	}
	return (rtn);
}
