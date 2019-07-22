/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:44 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/22 12:26:24 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*parse_group(gid_t gid)
{
	struct group	*gr_s;

	errno = 0;
	gr_s = getgrgid(gid);
	if (errno == 0)
		return (ft_strdup(gr_s->gr_name));
	else
	{
		perror("ft_ls (parse_group)");
		return (ft_strjoin("Error: ", strerror(errno)));
	}
}
