/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/29 11:07:38 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	get_type(mode_t mode)
{
	if ((mode & 0140000) == 0140000)
		return ('s');
	if ((mode & 0120000) == 0120000)
		return ('l');
	if ((mode & 0100000) == 0100000)
		return ('-');
	if ((mode & 0060000) == 0060000)
		return ('b');
	if ((mode & 0040000) == 0040000)
		return ('d');
	if ((mode & 0020000) == 0020000)
		return ('c');
	if ((mode & 0010000) == 0010000)
		return ('p');
	return ('?');
}

void	set_perms(mode_t mode, char *str)
{
	if ((mode & 0004000) == 0004000)
		str[2] = 'S';
	if ((mode & 0002000) == 0002000)
		str[5] = 'S';
	if ((mode & 0001000) == 0001000)
		str[8] = 'T';
	if ((mode & 0000400) == 0000400)
		str[0] = 'r';
	if ((mode & 0000200) == 0000200)
		str[1] = 'w';
	if ((mode & 0000100) == 0000100)
	{
		if (str[2] == 'S')
			str[2] = 's';
		else
			str[2] = 'x';
	}
	if ((mode & 0000040) == 0000040)
		str[3] = 'r';
	if ((mode & 0000020) == 0000020)
		str[4] = 'w';
	if ((mode & 0000010) == 0000010)
	{
		if (str[5] == 'S')
			str[5] = 's';
		else
			str[5] = 'x';
	}
	if ((mode & 0000004) == 0000004)
		str[6] = 'r';
	if ((mode & 0000002) == 0000002)
		str[7] = 'w';
	if ((mode & 0000001) == 0000001)
	{
		if (str[8] == 'T')
			str[8] = 't';
		else
			str[8] = 'x';
	}
}

void	parse_mode(mode_t mode, char *type, char **perms)
{
	*type = get_type(mode);
	*perms = ft_strdup("--------- ");
	set_perms(mode, *perms);
}
