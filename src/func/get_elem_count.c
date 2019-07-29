/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:46:44 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/29 11:50:30 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

size_t	get_elem_count(t_elem *elems)
{
	size_t	elem_count;

	elem_count = 0;
	while (elems[elem_count].name)
		elem_count++;
	return (elem_count);
}
