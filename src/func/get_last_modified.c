/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_modified.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:51 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/22 13:14:36 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

/*
** ctime returns:
** Thu Nov 24 18:22:48 1986\n\0
** strsub changes it to:
** Nov 24 18:22:48 1986\0
** strncpy copies just "Nov 24 ", rest of the string was already null
** 6 months * 183 days * 86400 seconds in a day
** if older than 6 months, concat "1986\0"
**  Nov 24 1986\0\0
** if more recent, concat "18:22\0"
**  Nov 24 18:22\0
*/

char	*get_last_modified(struct timespec tspec)
{
	time_t	seconds;
	time_t	age;
	char	*tmp;
	char	*rtn;

	seconds = tspec.tv_sec;
	age = time(NULL) - seconds;
	age = labs(age);
	tmp = ft_strsub(ctime(&seconds), 4, 20);
	rtn = ft_strnew(12);
	ft_strncpy(rtn, tmp, 7);
	if (age > (6 * 183 * 86400))
		ft_strncat(rtn, tmp + 16, 4);
	else
		ft_strncat(rtn, tmp + 7, 5);
	free(tmp);
	return (rtn);
}
