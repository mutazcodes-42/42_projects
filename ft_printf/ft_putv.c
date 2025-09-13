/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malfarah <malfarah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:33:01 by malfarah          #+#    #+#             */
/*   Updated: 2025/09/13 14:10:57 by malfarah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_rec(unsigned long p)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (p < 16)
		count += ft_putchar(*(base + p));
	else
	{
		count += ft_rec(p / 16);
		count += ft_rec(p % 16);
	}
	return (count);
}

int	ft_putv(void *x)
{
	unsigned long	p;
	int				count;

	if (!x)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (unsigned long)x;
	write(1, "0x", 2);
	count = ft_rec(p);
	return (count + 2);
}
