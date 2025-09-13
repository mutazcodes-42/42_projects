/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malfarah <malfarah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:15:25 by malfarah          #+#    #+#             */
/*   Updated: 2025/09/01 17:31:06 by malfarah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*string1;
	char	*string2;
	size_t	i;

	string1 = (char *)s1;
	string2 = (char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (string1[i] == string2[i] && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
