/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_slink_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:21:33 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/05 16:48:56 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*get_slink_target(char *path, MAXUNBR targetlen)
{
	char	*rtn;
	int		len;

	rtn = ft_memalloc(sizeof(*rtn) * (targetlen + 1));
	if ((len = readlink(path, rtn, targetlen + 1)) != -1)
	{
		rtn[len] = '\0';
		return (rtn);
	}
	else
	{
		put_error(errno, "readlink ", __func__);
		free(rtn);
		return (ft_strjoin("Error: ", strerror(errno)));
	}
}
