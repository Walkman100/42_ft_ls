/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:54:18 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/19 14:08:51 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	free_items(t_elem **items)
{
	t_elem	*tmp;

	tmp = *items;
	while ((*tmp).name)
	{
		MEMDEL((*tmp).perms);
		MEMDEL((*tmp).user);
		MEMDEL((*tmp).group);
		MEMDEL((*tmp).date);
		MEMDEL((*tmp).name);
		MEMDEL((*tmp).ln_target);
		tmp++;
	}
	ft_memdel((void **)items);
}
