/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:31:11 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/19 15:52:40 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		put_error(int errno_l, char *dbg, const char *caller_name)
{
	debug_2(dbg, caller_name);
	errno = errno_l;
	perror("ft_ls");
	return (-1);
}

void	exit_e(int errno_l, char *dbg, const char *caller_name)
{
	put_error(errno_l, dbg, caller_name);
	exit(EXIT_FAILURE);
}

int		put_error_path(int errno_l, char *path, char *dbg, \
														const char *caller_name)
{
	debug_2(dbg, caller_name);
	errno = errno_l;
	ft_putstr_fd("ft_ls: ", STDERR_FILENO);
	if (ft_strnequ(path, "./", 2))
		path += 2;
	else if (ft_strnequ(path, "//", 2))
		path++;
	if (*path == '\0')
		ft_putstr(": ");
	perror(path);
	return (-1);
}

void	exit_path(int errno_l, char *path, char *dbg, const char *caller_name)
{
	put_error_path(errno_l, path, dbg, caller_name);
	exit(EXIT_FAILURE);
}
