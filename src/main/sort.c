/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:13 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/30 12:37:52 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	sort_elems(t_elem *arr, long (*cmp)(t_elem, t_elem))
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

void	reverse_array(t_elem *arr)
{
	MAXUNBR	i;
	MAXUNBR	arr_len;
	t_elem	temp;

	i = 0;
	arr_len = get_elem_count(arr);
	while (i < arr_len / 2)
	{
		temp = arr[i];
		arr[i] = arr[arr_len - i - 1];
		arr[arr_len - i - 1] = temp;
		i++;
	}
}

void	sort_elem_array(t_elem *arr, t_args args)
{
	if (args.no_sort)
		return ;
	sort_elems(arr, cmp_name);
	if (args.sort_size)
		sort_elems(arr, cmp_size);
	else if (args.sort_time)
	{
		if (args.sort_access)
			sort_elems(arr, cmp_access);
		else
			sort_elems(arr, cmp_modified);
	}
	if (args.reverse_sort)
		reverse_array(arr);
}

void	sort_str_array(char **arr, t_args args)
{
	int		i;
	int		b_sorted;
	char	*temp;

	if (args.no_sort)
		return ;
	b_sorted = 0;
	while (b_sorted == 0)
	{
		b_sorted = 1;
		i = 0;
		while (arr[i] && arr[i + 1])
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
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
