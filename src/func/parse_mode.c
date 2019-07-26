/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/26 16:41:45 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	get_type(mode_t *mode)
{
	char	rtn;

	rtn = '?';
	if (*mode >= 0170000)
		*mode -= 0170000;
	if (*mode >= 0160000)
		*mode -= 0160000;
	if (*mode >= 0140000)
	{
		*mode -= 0140000;
		rtn = 's';
	}
	if (*mode >= 0120000)
	{
		*mode -= 0120000;
		rtn = 'l';
	}
	if (*mode >= 0100000)
	{
		*mode -= 0100000;
		rtn = '-';
	}
	if (*mode >= 0060000)
	{
		*mode -= 0060000;
		rtn = 'b';
	}
	if (*mode >= 0040000)
	{
		*mode -= 0040000;
		rtn = 'd';
	}
	if (*mode >= 0020000)
	{
		*mode -= 0020000;
		rtn = 'c';
	}
	if (*mode >= 0010000)
	{
		*mode -= 0010000;
		rtn = 'p';
	}
	return (rtn);
}

void	set_perms(mode_t *mode, char *str)
{
	if (*mode >= 0004000)
	{
		*mode -= 0004000;
		str[2] = 'S';
	}
	if (*mode >= 0002000)
	{
		*mode -= 0002000;
		str[5] = 'S';
	}
	if (*mode >= 0001000)
	{
		*mode -= 0001000;
		str[8] = 'T';
	}
	if (*mode >= 0000400)
	{
		*mode -= 0000400;
		str[0] = 'r';
	}
	if (*mode >= 0000200)
	{
		*mode -= 0000200;
		str[1] = 'w';
	}
	if (*mode >= 0000100)
	{
		*mode -= 0000100;
		if (str[2] == 'S')
			str[2] = 's';
		else
			str[2] = 'x';
	}
	if (*mode >= 0000040)
	{
		*mode -= 0000040;
		str[3] = 'r';
	}
	if (*mode >= 0000020)
	{
		*mode -= 0000020;
		str[4] = 'w';
	}
	if (*mode >= 0000010)
	{
		*mode -= 0000010;
		if (str[5] == 'S')
			str[5] = 's';
		else
			str[5] = 'x';
	}
	if (*mode >= 0000004)
	{
		*mode -= 0000004;
		str[6] = 'r';
	}
	if (*mode >= 0000002)
	{
		*mode -= 0000002;
		str[7] = 'w';
	}
	if (*mode >= 0000001)
	{
		*mode -= 0000001;
		if (str[8] == 'T')
			str[8] = 't';
		else
			str[8] = 'x';
	}
}

void	parse_mode(mode_t mode, char *type, char **perms)
{
	*type = get_type(&mode);
	*perms = ft_strdup("---------  ");
	set_perms(&mode, *perms);
}
