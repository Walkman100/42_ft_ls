/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_user.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:40 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/22 12:27:25 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

char	*parse_user(uid_t uid)
{
	struct passwd	*pw_s;

	errno = 0;
	pw_s = getpwuid(uid);
	if (errno == 0)
		return (ft_strdup(pw_s->pw_name));
	else
	{
		perror("ft_ls (parse_user)");
		return (ft_strjoin("Error: ", strerror(errno)));
	}
}
