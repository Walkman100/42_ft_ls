/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:05:26 by mcarter           #+#    #+#             */
/*   Updated: 2019/08/05 09:22:38 by mcarter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	putnbr_padl(MAXUNBR n, MAXUNBR total_len)
{
	MAXUNBR nlen;

	nlen = ft_unbrlen(n);
	while (nlen < total_len)
	{
		ft_putchar(' ');
		nlen++;
	}
	ft_putunbr(n);
}

void	putstr_padr(char *s, MAXUNBR total_len)
{
	MAXUNBR slen;

	slen = ft_strlen(s);
	ft_putstr(s);
	while (slen < total_len)
	{
		ft_putchar(' ');
		slen++;
	}
}

void	putstr_padr_c(char *s, char *clr, MAXUNBR total_len)
{
	MAXUNBR slen;

	slen = ft_strlen(s);
	ft_putstr(s);
	put_clr(clr);
	while (slen < total_len)
	{
		ft_putchar(' ');
		slen++;
	}
}
