/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malfarah <malfarah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:03:11 by malfarah          #+#    #+#             */
/*   Updated: 2025/09/14 17:15:30 by malfarah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch(char frmt, va_list list)
{
	int	count;

	count = 0;
	if (frmt == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (frmt == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (frmt == 'i' || frmt == 'd')
		count += ft_putnbr(va_arg(list, int));
	else if (frmt == 'u')
		count += ft_putunbr(va_arg(list, unsigned int));
	else if (frmt == 'p')
		count += ft_putv(va_arg(list, void *));
	else if (frmt == 'x' || frmt == 'X')
		count += ft_puthexa(va_arg(list, unsigned int), frmt);
	else if (frmt == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *frmt, ...)
{
	va_list	list;
	int		count;
	int		i;

	if (!frmt)
		return (-1);
	i = 0;
	count = 0;
	va_start(list, frmt);
	while (frmt[i])
	{
		if (frmt[i] == '%')
		{
			count += dispatch(frmt[i + 1], list);
			i += 2;
		}
		else
		{
			count += ft_putchar(frmt[i]);
			i++;
		}
	}
	va_end(list);
	return (count);
}
