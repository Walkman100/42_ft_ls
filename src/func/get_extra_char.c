/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extra_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:10:47 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/04 13:37:13 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

#ifdef __linux__

char	get_extra_char(char *path)
{
	if (listxattr(path, NULL, 0) > 0)
		return ('@');
	return (' ');
}

#else

char	get_extra_char(char *path)
{
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	return (' ');
}

#endif
