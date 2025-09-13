/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malfarah <malfarah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:59:09 by malfarah          #+#    #+#             */
/*   Updated: 2025/09/01 19:16:10 by malfarah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *s, char c)
{
	int	check;
	int	cntr;

	cntr = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && !check)
		{
			check = 1;
			cntr++;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (cntr);
}

static char	*ft_str(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static char	**ft_lazem(char c, const char *s, const char *x, char **res)
{
	size_t		len;
	const char	*start;
	int			i;

	i = 0;
	while (*x && i < ft_count((char *)s, c))
	{
		if (*x != c)
		{
			start = x;
			len = 0;
			while (*x && *x++ != c)
			{
				len++;
			}
			res[i] = ft_str(start, len);
			if (!res[i])
				return (NULL);
			i++;
		}
		else
			x++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	const char	*x;
	size_t		i;

	i = -1;
	if (!s)
		return (NULL);
	x = s;
	res = (char **)malloc((ft_count((char *)s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!ft_lazem(c, s, x, res))
	{
		while (res[++i])
			free(res[i]);
		free(res);
		res = NULL;
	}
	return (res);
}

// int	main(void) {
// 	const char *input = "This is a test string for splitting";
// 	char delimiter = ' ';
// 	char **split_array = ft_split(input, delimiter);
// 	int i = 0;
// 	while (split_array[i]) {
// 		printf("%s\n", split_array[i]);
// 			free(split_array[i]);
// 		i++;
// 	}
// free(split_array);

// 	return (0);
// }
