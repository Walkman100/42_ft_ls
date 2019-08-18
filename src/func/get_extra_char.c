/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extra_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:10:47 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/18 22:12:20 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

#ifdef __linux__

/*
** check for ACLs before xattrs on linux, as acls are implemented as xattrs
*/

char	get_extra_char(char *path)
{
	if (acl_extended_file(path) == 1)
		return ('+');
	if (listxattr(path, NULL, 0) > 0)
		return ('@');
	return (' ');
}

#else

char	get_extra_char(char *path)
{
	acl_t	tmp;

	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_file(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

#endif
