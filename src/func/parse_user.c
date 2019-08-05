/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_user.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:40 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/05 16:49:06 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*parse_user(uid_t uid)
{
	struct passwd	*pw_s;

	errno = 0;
	pw_s = getpwuid(uid);
	if (pw_s)
		return (ft_strdup(pw_s->pw_name));
	else if (errno)
		put_error(errno, "getpwuid ", __func__);
	return (ft_itoa(uid));
}
