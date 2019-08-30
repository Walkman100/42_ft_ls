/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_slink_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:21:33 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/30 13:55:12 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*get_slink_target(char *path, MAXUNBR targetlen)
{
	char	*rtn;
	int		len;

	if (!targetlen)
		targetlen = 128;
	rtn = ft_strnew(targetlen);
	if ((len = readlink(path, rtn, targetlen)) != -1)
	{
		rtn[len] = '\0';
		return (rtn);
	}
	put_error(errno, "readlink ", __func__);
	MEMDEL(rtn);
	return (ft_strjoin("Error: ", strerror(errno)));
}
