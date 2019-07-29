/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:13 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/29 15:31:35 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	sort_elems(t_elem *arr, int (*cmp)(t_elem, t_elem))
{
	int		i;
	int		b_sorted;
	t_elem	temp;

	b_sorted = 0;
	while (b_sorted == 0)
	{
		b_sorted = 1;
		i = 0;
		while (arr[i].name && arr[i + 1].name)
		{
			if (cmp(arr[i], arr[i + 1]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				b_sorted = 0;
			}
			i++;
		}
	}
}

void	sort_elems_reverse(t_elem *arr, int (*cmp)(t_elem, t_elem))
{
	int		i;
	int		b_sorted;
	t_elem	temp;

	b_sorted = 0;
	while (b_sorted == 0)
	{
		b_sorted = 1;
		i = 0;
		while (arr[i].name && arr[i + 1].name)
		{
			if (cmp(arr[i], arr[i + 1]) < 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				b_sorted = 0;
			}
			i++;
		}
	}
}

void	sort_elem_array(t_elem *arr, t_args args)
{
	int	(*cmp)(t_elem, t_elem);

	if (args.no_sort)
		return ;
	else if (args.sort_time)
	{
		if (args.sort_access)
			cmp = cmp_access;
		else
			cmp = cmp_modified;
	}
	else
		cmp = cmp_name;
	if (args.reverse_sort == 0)
		sort_elems(arr, cmp);
	else
		sort_elems_reverse(arr, cmp);
}
