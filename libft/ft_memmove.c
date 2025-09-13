/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malfarah <malfarah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:10:12 by malfarah          #+#    #+#             */
/*   Updated: 2025/08/31 14:20:17 by malfarah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;

	cdst = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (csrc < cdst)
	{
		while (n--)
			*(cdst + n) = *(csrc + n);
	}
	else
	{
		while (n--)
			*cdst++ = *csrc++;
	}
	return (dest);
}

/*int main(void)
{

	char str[] = "mutazmutaz";
	char str1[] = "mutazmutaz";

	printf("%s\n",(char *)memmove((void *)str,(void *)str + 2,5));
		printf("%s",(char *)ft_memmove((void *)str1,(void *)str1 + 2,5));



}*/
