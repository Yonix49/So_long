/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:12:33 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/02/21 16:59:23 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include <stddef.h>
#include <stdlib.h>

static int	numbrers_words(char *str, char c, size_t t)
{
	size_t	i;
	int		nb_words;

	i = 0;
	nb_words = 0;
	while (i < t && str[i])
	{
		if (str[i] != c && ((i == 0 || str[i - 1] == c)))
			nb_words++;
		i++;
	}
	return (nb_words);
}

static	int	word_len(char *str, int i, char c)
{
	int	z;

	z = 0;
	while (str[i] && str[i] != c)
	{
		z++;
		i++;
	}
	return (z);
}

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static	void	assemblage(char **tab, char *str, int i, char c)
{
	int	k;
	int	j;

	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] == c)
			i++;
		if (str[i])
		{
			tab [j] = (char *)malloc(word_len(str, i, c) + 1 * sizeof(char));
			if (!tab[j])
				ft_malloc_error(tab);
			while (str[i] && str[i] != c)
			{
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
}

char	**ft_split(char *s, char c)
{
	char	*str;
	char	**tab;
	int		i;

	i = 0;
	str = (char *)s;
	tab = malloc((numbrers_words(str, c, ft_strlen(str)) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	assemblage (tab, str, i, c);
	return (tab);
}

// int main ()
// {
// 	char **tab;
// const char s [] = "1111111111111111111111111111111111
// 1E0000000000000C00000C000000000001
// 1010010100100000101001000000010101
// 1010010010101010001001000000010101
// 1P0000000C00C0000000000000000000C1
// 1111111111111111111111111111111111";
// 	char c = ' ';
// 	int i;
// 	i = 0;
// 	tab = ft_split(s, c);
// 	while(i < 8)
// 	{
// 		printf("tab[%d] = %s\n" , i , tab[i]);
// 		i++;
// 	}
// 	return (0);
// }