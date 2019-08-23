/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:30:52 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/23 16:21:38 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

long	cmp_name(t_elem elem1, t_elem elem2)
{
	return (ft_strcmp(elem1.name, elem2.name));
}

long	cmp_modified(t_elem elem1, t_elem elem2)
{
	if (elem2.mtime != elem1.mtime)
		return (elem2.mtime - elem1.mtime);
	else
		return (elem2.mtimenano - elem1.mtimenano);
}

long	cmp_access(t_elem elem1, t_elem elem2)
{
	if (elem2.atime != elem1.atime)
		return (elem2.atime - elem1.atime);
	else
		return (elem2.mtimenano - elem1.mtimenano);
}
