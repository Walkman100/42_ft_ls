/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:51 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/19 11:38:07 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

/*
** ctime returns:
** Thu Nov 24 18:22:48 1986\n\0
** strsub changes it to:
** Nov 24 18:22:48 1986\0
** strncpy copies just "Nov 24 ", rest of the string was already null
** 6 months = 183 days * 86400 seconds in a day
** if older than 6 months, concat " 1986\0"
**  Nov 24  1986\0
** if more recent, concat "18:22\0"
**  Nov 24 18:22\0
**
** EXCEPT on 5-digit years: (tmp[19] == ' ') ctime returns:
** Sat Jan  1 00:59:00     10000\n\0
** strsub changes it to:
** Jan  1 00:59:00     \0
** strncpy copies just "Jan  1 "
** if older than 6 months, concat " 10000\0" (from ctime call)
*/

char	*get_time_str(time_t seconds)
{
	time_t	age;
	char	*tmp;
	char	*rtn;

	age = time(NULL) - seconds;
	age = labs(age);
	tmp = ft_strsub(ctime(&seconds), 4, 20);
	rtn = ft_strnew(tmp[19] != ' ' ? 12 : 13);
	ft_strncpy(rtn, tmp, 7);
	if (age > (183 * 86400))
	{
		if (tmp[19] != ' ')
			ft_strncat(rtn, tmp + 15, 5);
		else
			ft_strncat(rtn, ctime(&seconds) + 23, 6);
	}
	else
		ft_strncat(rtn, tmp + 7, 5);
	free(tmp);
	return (rtn);
}
