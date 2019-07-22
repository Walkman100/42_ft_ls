/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_slink_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:21:33 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/22 11:54:58 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*get_slink_target(char *path, MAXUNBR targetlen)
{
	char	*rtn;
	int		len;

	rtn = ft_memalloc((targetlen + 1) * sizeof(*rtn));
	if ((len = readlink(path, rtn, targetlen + 1)) != -1)
	{
		rtn[len] = '\0';
		return (rtn);
	}
	else
	{
		perror("ft_ls (get_slink_target)");
		free(rtn);
		return (ft_strjoin("Error: ", strerror(errno)));
	}
}
