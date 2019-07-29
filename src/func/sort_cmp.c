/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:30:52 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/29 15:33:23 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		cmp_name(t_elem elem1, t_elem elem2)
{
	return (ft_strcmp(elem1.name, elem2.name));
}

int		cmp_modified(t_elem elem1, t_elem elem2)
{
	return (elem1.mtime - elem2.mtime);
}

int		cmp_access(t_elem elem1, t_elem elem2)
{
	return (elem1.atime - elem2.atime);
}
