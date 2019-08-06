/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 09:54:18 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/06 10:11:48 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	free_items(t_elem **items)
{
	t_elem	*tmp;

	tmp = *items;
	while ((*tmp).name)
	{
		ft_memdel((void **)&(*tmp).perms);
		ft_memdel((void **)&(*tmp).user);
		ft_memdel((void **)&(*tmp).group);
		ft_memdel((void **)&(*tmp).date);
		ft_memdel((void **)&(*tmp).name);
		ft_memdel((void **)&(*tmp).ln_target);
		tmp++;
	}
	ft_memdel((void **)items);
}
