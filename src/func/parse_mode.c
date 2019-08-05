/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:34 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/05 13:15:39 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	get_type(mode_t mode)
{
	if ((mode & S_IFSOCK) == S_IFSOCK)
		return ('s');
	if ((mode & S_IFLNK) == S_IFLNK)
		return ('l');
	if ((mode & S_IFREG) == S_IFREG)
		return ('-');
	if ((mode & S_IFBLK) == S_IFBLK)
		return ('b');
	if ((mode & S_IFDIR) == S_IFDIR)
		return ('d');
	if ((mode & S_IFCHR) == S_IFCHR)
		return ('c');
	if ((mode & S_IFIFO) == S_IFIFO)
		return ('p');
	return ('?');
}

void	set_perms(mode_t mode, char *str)
{
	if ((mode & S_ISUID) == S_ISUID)
		str[2] = 'S';
	if ((mode & S_ISGID) == S_ISGID)
		str[5] = 'S';
	if ((mode & S_ISVTX) == S_ISVTX)
		str[8] = 'T';
	if ((mode & S_IRUSR) == S_IRUSR)
		str[0] = 'r';
	if ((mode & S_IWUSR) == S_IWUSR)
		str[1] = 'w';
	if ((mode & S_IXUSR) == S_IXUSR)
		str[2] = (str[2] == 'S') ? 's' : 'x';
	if ((mode & S_IRGRP) == S_IRGRP)
		str[3] = 'r';
	if ((mode & S_IWGRP) == S_IWGRP)
		str[4] = 'w';
	if ((mode & S_IXGRP) == S_IXGRP)
		str[5] = (str[5] == 'S') ? 's' : 'x';
	if ((mode & S_IROTH) == S_IROTH)
		str[6] = 'r';
	if ((mode & S_IWOTH) == S_IWOTH)
		str[7] = 'w';
	if ((mode & S_IXOTH) == S_IXOTH)
		str[8] = (str[8] == 'T') ? 't' : 'x';
}

void	parse_mode(mode_t mode, char *type, char **perms)
{
	*type = get_type(mode);
	*perms = ft_strdup("--------- ");
	set_perms(mode, *perms);
}
