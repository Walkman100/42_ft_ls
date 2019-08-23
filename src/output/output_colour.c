/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_colour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:31:15 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/23 10:42:15 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

/*
**  default colours on mac: (foreground, background)
** blue, default	d - directory
** magenta, default	l - symbolic link
** green, default	s - socket
** yellow, default	p - pipe (FIFO)
** red, default		executable
** blue, cyan		b - block special
** blue, yellow		c - character special
** black, red		executable with setuid bit set
** black, cyan		executable with setgid bit set
** black, green		directory writable to others, with sticky bit
** black, yellow	directory writable to others, without sticky bit
**
**  default colours on linux: (foreground, background)
** 0, 0						FILE	regular file
** 0, 0						RESET	reset to "normal" color
** bold blue, default		DIR		directory
** bold cyan, default		LINK	symbolic link
** bold magenta, default	SOCK	socket
** yellow, black			FIFO	pipe
** bold green, default		EXEC	files with execute permission
** bold yellow, black		BLK		block device driver
** bold yellow, black		CHR		character device driver
** white, red				SETUID	file that is setuid (u+s)
** black, yellow			SETGID	file that is setgid (g+s)
** black, green		STICKY_OTHER_WRITABLE	dir that is sticky and
**														other-writable (+t,o+w)
** blue, green				OTHER_WRITABLE	dir that is other-writable (o+w) and
**														not sticky
** white, blue				STICKY	dir with the sticky bit set (+t) and not
**														other-writable
** bold magenta, default	DOOR	door
** bold red, black			ORPHAN	symlink to nonexistent file, or
**														non-stat'able file ...
** 0, 0						MISSING	... and the files they point to
** black, red				CAPABILITY	file with capability
**
** also see https://geoff.greer.fm/lscolors/
*/

void	output_colour(char type, char *perms)
{
	if (type == 'd')
		if (perms[7] == 'w' && (perms[8] == 't' || perms[8] == 'T'))
			put_clr(BLACK "" BCK_GREEN);
		else if (perms[7] == 'w')
			put_clr(BLACK "" BCK_YELLOW);
		else
			put_clr(BLUE);
	else if (type == 'l')
		put_clr(MAGENTA);
	else if (type == 's')
		put_clr(GREEN);
	else if (type == 'p')
		put_clr(YELLOW);
	else if (type == 'b')
		put_clr(BLUE "" BCK_CYAN);
	else if (type == 'c')
		put_clr(BLUE "" BCK_YELLOW);
	else if (perms[2] == 's')
		put_clr(BLACK "" BCK_RED);
	else if (perms[5] == 's')
		put_clr(BLACK "" BCK_CYAN);
	else if (perms[2] == 'x' || perms[5] == 'x' || \
											perms[8] == 'x' || perms[8] == 't')
		put_clr(RED);
}
