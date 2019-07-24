/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_colour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:31:15 by mcarter           #+#    #+#             */
/*   Updated: 2019/07/24 17:01:59 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

/*
**  default colours on mac:
** ex d - directory
** fx l - symbolic link
** cx s - socket
** dx p - pipe (FIFO)
** bx executable
** eg b - block special
** ed c - character special
** ab executable with setuid bit set
** ag executable with setgid bit set
** ac directory writable to others, with sticky bit
** ad directory writable to others, without sticky bit
**
**  codes:
** a     black
** b     red
** c     green
** d     yellow
** e     blue
** f     magenta
** g     cyan
** h     white
** A     bold black
** B     bold red
** C     bold green
** D     bold yellow
** E     bold blue
** F     bold magenta
** G     bold cyan
** H     bold white
** x     default
*/

void	output_colour(char type)
{
	if (type == 'd')
		put_clr(BLUE);
	else if (type == 'l')
		put_clr(MAGENTA);
	else if (type == 's')
		put_clr(GREEN);
	else if (type == 'p')
		put_clr(YELLOW);
	else if (type == 'b')
	{
		put_clr(BLUE);
		put_clr(BCK_CYAN);
	}
	else if (type == 'c')
	{
		put_clr(BLUE);
		put_clr(BCK_YELLOW);
	}
}
