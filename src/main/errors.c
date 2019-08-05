/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:31:11 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/05 15:14:07 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	put_error(int errno_l, char *dbg, const char *caller_name)
{
	debug_2(dbg, caller_name);
	errno = errno_l;
	perror("ft_ls");
}

void	exit_e(int errno_l, char *dbg, const char *caller_name)
{
	put_error(errno_l, dbg, caller_name);
	exit(EXIT_FAILURE);
}

void	exit_path(int errno_l, char *path, char *dbg, const char *caller_name)
{
	debug_2(dbg, caller_name);
	errno = errno_l;
	ft_putstr_fd("ft_ls: ", STDERR_FILENO);
	perror(path);
	exit(EXIT_FAILURE);
}
