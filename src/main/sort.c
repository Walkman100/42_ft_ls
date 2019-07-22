/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:13 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/18 16:31:21 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	sort_elems_name(t_elem *arr)
{
	
}

void	sort_elems_modified_time(t_elem *arr, char reverse)
{
	
}

void	sort_elems_access_time(t_elem *arr, char reverse)
{
	
}

void	sort_elem_array(t_elem *arr, t_args args)
{
	if (args.no_sort)
		return ;
	else if (args.sort_time)
	{
		if (args.sort_access)
			sort_elems_access_time(arr, args.reverse_sort);
		else
			sort_elems_modified_time(arr, args.reverse_sort);
	}
	else
		sort_elems_name(arr);
}
