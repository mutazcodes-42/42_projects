/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malfarah <malfarah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:39:29 by malfarah          #+#    #+#             */
/*   Updated: 2025/09/11 17:19:10 by malfarah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (nbr >= 10)
	{
		count += ft_putunbr(nbr / 10);
		count += ft_putchar((nbr % 10) + '0');
	}
	else
	{
		count += ft_putchar(nbr + '0');
	}
	return (count);
}
