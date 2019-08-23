/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:30:52 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/23 12:34:54 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

long	cmp_name(t_elem elem1, t_elem elem2)
{
	return (ft_strcmp(elem1.name, elem2.name));
}

long	cmp_modified(t_elem elem1, t_elem elem2)
{
	return (elem2.mtime - elem1.mtime);
}

long	cmp_access(t_elem elem1, t_elem elem2)
{
	return (elem2.atime - elem1.atime);
}
