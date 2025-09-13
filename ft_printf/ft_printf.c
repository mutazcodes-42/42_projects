/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malfarah <malfarah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:03:11 by malfarah          #+#    #+#             */
/*   Updated: 2025/09/13 14:14:51 by malfarah         ###   ########.fr       */
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

// #include "ft_printf.h"
// #include <limits.h>

// int	main(void)
// {
// 	int	x;

// 	int ret1, ret2;
//     ret1 = ret2 = 0;
// 	// Characters
// 	ret1 = ft_printf("My char: %c\n", 'A');
// 	ret2 = printf("ys char: %c\n", 'A');
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	// Strings
// 	ret1 = ft_printf("My string: %s\n", "Hello, world!");
// 	ret2 = printf("ys string: %s\n", "Hello, world!");
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	// Integers
// 	ret1 = ft_printf("My int: %d\n", 12345);
// 	ret2 = printf("ys int: %d\n", 12345);
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	// Negative integers
// 	ret1 = ft_printf("My neg int: %i\n", -54321);
// 	ret2 = printf("ys neg int: %i\n", -54321);
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	// Unsigned
// 	ret1 = ft_printf("My unsigned: %u\n", 3000000000u);
// 	ret2 = printf("ys unsigned: %u\n", 3000000000u);
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	// Hex lowercase
// 	ret1 = ft_printf("My hex (lower): %x\n", 0xdeadbeef);
// 	ret2 = printf("ys hex (lower): %x\n", 0xdeadbeef);
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	// Hex uppercase
// 	ret1 = ft_printf("My hex (upper): %X\n", 0xDEADBEEF);
// 	ret2 = printf("ys hex (upper): %X\n", 0xDEADBEEF);
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	// Pointer
// 	x = 42;
// 	ret1 = ft_printf("My pointer: %p\n", &x);
// 	ret2 = printf("ys pointer: %p\n", &x);
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	// Percent sign
// 	ret1 = ft_printf("My percent: %%\n");
// 	ret2 = printf("ys percent: %%\n");
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	// Edge cases
// 	ret1 = ft_printf("My INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
// 	ret2 = printf("ys INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	ret1 = ft_printf("My NULL string: %s\n", (char *)NULL);
// 	ret2 = printf("ys NULL string: %s\n", (char *)NULL);
// 	printf("Return values: mine=%d, sys=%d\n\n", ret1, ret2);
// 	return (0);
// }
